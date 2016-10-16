#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE (1024)
#define INODE_SIZE (128)
#define SUPER_BLOCK_OFFSET (1024)
#define BLOCK_GROUP_DESC_OFFSET (SUPER_BLOCK_OFFSET + BLOCK_SIZE)

enum {
    EXT2_FT_UNKNOWN = 0,
    EXT2_FT_REG_FILE = 1,
    EXT2_FT_DIR = 2,
    EXT2_FT_CHRDEV = 3,
    EXT2_FT_BLKDEV = 4,
    EXT2_FT_FIFO = 5,
    EXT2_FT_SOCK = 6,
    EXT2_FT_SYMLINK = 7,
    EXT2_FT_MAX
};

struct ext2_super_block {
    uint32_t s_inodes_count;        /* Inodes count */
    uint32_t s_blocks_count;        /* Blocks count */
    uint32_t s_inodes_per_group;    /* # Inodes per group */
};

struct ext2_group_desc {
    uint32_t bg_block_bitmap;       /* Blocks bitmap block */
    uint32_t bg_inode_bitmap;       /* Inodes bitmap block */
    uint32_t bg_inode_table;        /* Inodes table block */
};

#define	EXT2_NDIR_BLOCKS 12
#define	EXT2_IND_BLOCK EXT2_NDIR_BLOCKS
#define	EXT2_DIND_BLOCK (EXT2_IND_BLOCK + 1)
#define	EXT2_TIND_BLOCK (EXT2_DIND_BLOCK + 1)
#define	EXT2_N_BLOCKS (EXT2_TIND_BLOCK + 1)

struct ext2_inode {
    uint32_t i_blocks;              /* Blocks count */
    uint32_t i_block[EXT2_N_BLOCKS];/* Pointers to blocks */
};

#define EXT2_NAME_LEN 255

struct ext2_dir_entry {
	uint32_t inode;            /* Inode number */
	uint16_t rec_len;          /* Directory entry length */
	uint8_t name_len;          /* Name length */
	uint8_t file_type;
	char name[EXT2_NAME_LEN];  /* File name */
};

typedef struct ext2_super_block *ext2_super_block_p;
typedef struct ext2_group_desc *ext2_group_desc_p;
typedef struct ext2_inode *ext2_inode_p;
typedef struct ext2_dir_entry *ext2_dir_entry_p;

void output_dir_file(uint8_t *ext2, \
    ext2_dir_entry_p de, ext2_group_desc_p bg, \
    FILE *output, int depth);

uint8_t *read_ext2(FILE *f) {
    fseek(f, 0L, SEEK_END);
    uint32_t file_size = ftell(f);
    printf("%d\n", file_size);
    fseek(f, 0L, SEEK_SET);
    uint8_t *data = (uint8_t *)malloc(sizeof(uint8_t) * file_size);
    if(data == NULL) {
        fprintf(stderr, "Memory allocated failure!!(%s)", __func__);
        exit(1);
    }

    for(uint32_t i = 0; i < file_size; i++) {
        data[i] = fgetc(f);
    }

    printf("%c %d\n", data[44944], data[44944]);
    return data;
}

uint32_t read_data_with_little_endian_32(uint8_t *ext2) {
    uint32_t data = 0;
    for(int i = 3; i >= 0; i--) {
        data += ext2[i];
        if(i != 0) data <<= 8;
    }

    return data;
}

uint16_t read_data_with_little_endian_16(uint8_t *ext2) {
    uint16_t data = 0;
    for(int i = 1; i >= 0; i--) {
        data += ext2[i];
        if(i != 0) data <<= 8;
    }

    return data;
}

uint8_t read_data_with_little_endian_8(uint8_t *ext2) {
    uint8_t data = ext2[0];

    return data;
}

ext2_super_block_p read_super_block(uint8_t *ext2) {
    ext2_super_block_p sb = (ext2_super_block_p)malloc(sizeof(struct ext2_super_block));
    if(sb == NULL) {
        fprintf(stderr, "Memory allocated failure!!(%s)", __func__);
        exit(1);
    }

    sb->s_inodes_count = read_data_with_little_endian_32(&ext2[SUPER_BLOCK_OFFSET]);
    sb->s_blocks_count = read_data_with_little_endian_32(&ext2[SUPER_BLOCK_OFFSET + 4]);
    sb->s_inodes_per_group = read_data_with_little_endian_32(&ext2[SUPER_BLOCK_OFFSET + 40]);
    printf("%u %u %u\n", sb->s_inodes_count, sb->s_blocks_count, sb->s_inodes_per_group);
    return sb;
}

ext2_group_desc_p read_group_desc(uint8_t *ext2) {
    ext2_group_desc_p bg = (ext2_group_desc_p)malloc(sizeof(struct ext2_group_desc));
    if(bg == NULL) {
        fprintf(stderr, "Memory allocated failure!!(%s)", __func__);
        exit(1);
    }

    bg->bg_block_bitmap = read_data_with_little_endian_32(&ext2[BLOCK_GROUP_DESC_OFFSET]);
    bg->bg_inode_bitmap = read_data_with_little_endian_32(&ext2[BLOCK_GROUP_DESC_OFFSET + 4]);
    bg->bg_inode_table = read_data_with_little_endian_32(&ext2[BLOCK_GROUP_DESC_OFFSET + 8]);
    printf("%x %x %x\n", bg->bg_block_bitmap, bg->bg_inode_bitmap, bg->bg_inode_table);
    return bg;
}

ext2_inode_p read_inode(uint8_t *ext2, uint32_t offset) {
    ext2_inode_p inode = (ext2_inode_p)malloc(sizeof(struct ext2_inode));
    if(inode == NULL) {
        fprintf(stderr, "Memory allocated failure!!(%s)", __func__);
        exit(1);
    }

    inode->i_blocks = read_data_with_little_endian_32(&ext2[offset + 28]);
    for(uint32_t i = 0; i < EXT2_N_BLOCKS; i++) {
        inode->i_block[i] = read_data_with_little_endian_32(&ext2[offset + 40 + i * 4]);
        //printf("%d ", inode->i_block[i]);
    }
    //printf("\n");

    return inode;
}

ext2_dir_entry_p read_dir_entry(uint8_t *ext2, uint32_t offset) {
    ext2_dir_entry_p de = (ext2_dir_entry_p)malloc(sizeof(struct ext2_dir_entry));
    if(de == NULL) {
        fprintf(stderr, "Memory allocated failure!!(%s)", __func__);
        exit(1);
    }

    de->inode = read_data_with_little_endian_32(&ext2[offset]);
    de->rec_len = read_data_with_little_endian_16(&ext2[offset + 4]);
    de->name_len = read_data_with_little_endian_8(&ext2[offset + 6]);
    de->file_type = read_data_with_little_endian_8(&ext2[offset + 7]);
    memset(de->name, 0, sizeof(char) * EXT2_NAME_LEN);
    for(uint8_t i = 0; i < de->name_len; i++) {
        de->name[i] = read_data_with_little_endian_8(&ext2[offset + 8 + i]);
    }
    printf("%x %x %s\n", de->inode, de->name_len, de->name);;
    return de;
}

void output_data_of_one_block_rf(uint8_t *ext2, uint32_t block_offset, \
    FILE *output, int depth) {
    for(int i = 0; i < depth; i++) {
        fprintf(output, "  ");
    }
    for(int i = 0; i < 1024; i++) {
        if(ext2[block_offset + i] != 0) {
            fprintf(output, "%c", ext2[block_offset +i]);
        }
    }
}

void output_regular_file(uint8_t *ext2, \
    ext2_dir_entry_p rf, ext2_group_desc_p bg, \
    FILE *output, int depth) {
    for(int i = 0; i < depth - 1; i++) {
        fprintf(output, "  ");
    }
    fprintf(output, "%s(rf)\n",rf->name);

    uint32_t inode_offset = (rf->inode - 1) * INODE_SIZE + bg->bg_inode_table * BLOCK_SIZE;
    ext2_inode_p inode = read_inode(ext2, inode_offset);
    for(uint32_t i = 0; i < EXT2_N_BLOCKS; i++) {
        if(inode->i_block[i] != 0) {
            output_data_of_one_block_rf(ext2, inode->i_block[i] * BLOCK_SIZE, output, depth);
        }
    }

    fprintf(output, "\n");
}

void output_data_of_one_block_de(uint8_t *ext2, \
    uint32_t block_offset, \
    ext2_group_desc_p bg, \
    FILE *output, int depth) {
    for(uint32_t i = 0; ext2[block_offset + i] != 0; ) {
        for(int i = 0; i < depth; i++) {
            fprintf(output, "  ");
        }
        ext2_dir_entry_p cur_file = read_dir_entry(ext2, block_offset + i);
        if(strcmp(cur_file->name, ".") == 0 || strcmp(cur_file->name, "..") == 0) {
            fprintf(output, "%s\n", cur_file->name);
        } else {
            if(cur_file->file_type == EXT2_FT_DIR) {
                output_dir_file(ext2, cur_file, bg, output, depth + 1);
            } else if(cur_file->file_type == EXT2_FT_REG_FILE) {
                output_regular_file(ext2, cur_file, bg, output, depth);
            } else {
                /* ... */
            }
        }

        i += cur_file->rec_len;
        fprintf(output, "\n");
    }
}

void output_dir_file(uint8_t *ext2, \
    ext2_dir_entry_p de, ext2_group_desc_p bg, \
    FILE *output, int depth) {
    for(int i = 0; i < depth - 1; i++) {
        fprintf(output, "  ");
    }
    fprintf(output, "%s(dir)\n", de->name);

    uint32_t inode_offset = (de->inode - 1) * INODE_SIZE + bg->bg_inode_table * BLOCK_SIZE;
    ext2_inode_p inode = read_inode(ext2, inode_offset);
    for(uint32_t i = 0; i < EXT2_N_BLOCKS; i++) {
        if(inode->i_block[i] != 0) {
            printf("i_block: %u %u\n", inode->i_block[i], i);
            output_data_of_one_block_de(ext2, inode->i_block[i] * BLOCK_SIZE, bg, output, depth);
        }
    }

    fprintf(output, "\n");
}

void go_go_go(void) {
    FILE *f = fopen("ext2.img", "rb");
    FILE *output = fopen("output.txt", "w+");
    uint8_t *ext2 = read_ext2(f);
    ext2_super_block_p sb = read_super_block(ext2);
    ext2_group_desc_p bg = read_group_desc(ext2);
    uint32_t root_inode_offset = bg->bg_inode_table * BLOCK_SIZE + INODE_SIZE;
    ext2_inode_p root_inode = read_inode(ext2, root_inode_offset);
    uint32_t root_dir_entry_offset =  root_inode->i_block[0] * BLOCK_SIZE;
    ext2_dir_entry_p root_dir_entry = read_dir_entry(ext2, root_dir_entry_offset);
    output_dir_file(ext2, root_dir_entry, bg, output, 0);
    fclose(f);
    fclose(output);
}

int main(void) {
    go_go_go();
    return 0;
}
