/* Tower of hanoi */
#include <stdio.h>

/*
   Suppose we have N disks which are numbered with {1, 2, 3, ... , N}, and 
   smaller number with smaller disk. 

   We say that a disk in position(m, n) if the disk is nth disk(buttom to top)
   of mth rod(left to right).

   n_disk[i] is the number of disks on ith rod.
   rod[i][j] is the No. of disk in position(i+1, j+1). but if j >= n_disk[i],
   rod[i][j] means nothing.

   We use array rod to help us drawing towers after every movement.

   The array disk stores character graphs of disks.
*/

#define N 3

int rod[3][N];
int n_disk[3];
int disk[N + 1][2 * N + 1];

// Function <output_a_slice> draws a disk if we need, or just draws a rod.
void output_a_slice(
    int r,
    int k
    )
{
    for(int i = 0; i < 2 * N + 1; i++) {
        // we need to insure there is a disk in position(r+1, k+1)
        putchar(disk[n_disk[r] - 1 >= k ? rod[r][k] : 0][i]);
    }
}

// Function <disp> draws the towers with disks.
void disp(
    void
    )
{
    for(int i = 0; i < (N * 2 + 1) * 3 - N; i++) {
        if((i + N - 1) % (2 * N)) {
            putchar(' ');
        } else {
            putchar('A' + (i + N - 1) / (2 * N) - 1);
        }
    }

    putchar('\n');

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j < 3; j++) {
            output_a_slice(j, N - i);
        }

        putchar('\n');
    }

    for(int i = 0; i < (2 * N + 1) * 3; i++) {
        putchar('~');
    }
    putchar('\n');
}

void rod_push(
    int r,
    int v
    )
{
    rod[r][n_disk[r]++] = v;
}

int rod_pop(
    int r
    )
{
    return rod[r][--n_disk[r]];
}

void move(
    int from,
    int to
    )
{
    static int seq;
    printf("%d, Move disk %d from %c to %c. \n\n",
        ++seq,
        rod[from][n_disk[from] - 1],
        'A' + from,
        'A' + to);
    rod_push(to, rod_pop(from));
    disp();
}

void hanoi(
    int n,
    int a,
    int b,
    int c
    )
{
    if(n > 0) {
        hanoi(n - 1, a, c, b);
        move(a, b);
        hanoi(n - 1, c, b, a);
    }
}

void init(
    void
    )
{
    for(int i = 0; i < N; i++) {
        rod[0][i] = N - i;
    }

    n_disk[0] = N;

    // ith disk : (((...((i))...))), i pairs of brackets.
    // the array disk includes character graphs of all N disks.
    // if a position has no disk, we just draw the character '|' represents rod.
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(j == N) {
                disk[i][j] = (i == 0) ? '|' : ('0' + i);
            } else if(j < N - i) {
                disk[i][j] = disk[i][2 * N - j] = ' ';
            } else {
                disk[i][j] = '(';
                disk[i][2 * N - j] = ')';
            }
        }
    }
}

int main(
    void
    )
{
    init();
    disp();
    hanoi(N, 0, 2, 1);
    return 0;
}
