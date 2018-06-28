/**
 * Maximum path sum I & II
 * Myyyura
 */

/**
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 * 
 * 3
 * 7 4
 * 2 4 6
 * 8 5 9 3
 * 
 * That is, 3 + 7 + 4 + 9 = 23.
 * 
 * Find the maximum total from top to bottom of the triangle below:
 * 
 * 75
 * 95 64
 * 17 47 82
 * 18 35 87 10
 * 20 04 82 47 65
 * 19 01 23 75 03 34
 * 88 02 77 73 07 63 67
 * 99 65 04 28 06 16 70 92
 * 41 41 26 56 83 40 80 70 33
 * 41 48 72 33 47 32 37 16 94 29
 * 53 71 44 65 25 43 91 52 97 51 14
 * 70 11 33 28 77 73 17 78 39 68 17 57
 * 91 71 52 38 17 14 91 43 58 50 27 29 48
 * 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 */

#include <stdio.h>

int triangle[100][100] = {-1};
int max_path[100][100] = {-1};

int read_data(FILE* input) {
    char buffer[1000];
    int lines = 0;
    while (fgets(buffer, 1000, input) != NULL) {
        lines++;
        for (int j = 0; j < lines; j++) {
            sscanf(buffer + j * 3, "%d", &triangle[lines - 1][j]);
        }
    }

    return lines;
}

int max(int a, int b) {
    return a > b ? a : b;
}

/**
 * To get to position [i, j] in one step, we must already in position 
 * [i - 1, j - 1] or [i - 1, j].
 */
int maximum_path_sum_dp(int n) {
    max_path[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int temp1 = 0, temp2 = 0;
            if (j > 0) {
                temp1 = max_path[i - 1][j - 1] + triangle[i][j];
            }

            if (j < i) {
                temp2 = max_path[i - 1][j] + triangle[i][j];
            }

            max_path[i][j] = max(temp1, temp2);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, max_path[n - 1][i]);
    }

    return result;
}

int main(void) {
    FILE *data_18 = fopen("../../data/p18.txt", "r");
    int line_18 = read_data(data_18);
    fclose(data_18);

    FILE *data_67 = fopen("../../data/p67.txt", "r");
    int line_67 = read_data(data_67);
    fclose(data_67);

    printf("p18: %d\n", maximum_path_sum_dp(line_18));
    printf("p67: %d\n", maximum_path_sum_dp(line_67));
    return 0;
}