/**
 * Number spiral diagonals
 * Myyura
 */

/**
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 * 
 * 1 7 21 43 ... 4n^2 + 2n + 1 = a_n
 * 1 9 25 49 ... 4n^2 + 4n + 1 = b_n
 * 1 5 17 37 ... 4n^2 + 1 = c_n
 * 1 3 13 31 ... 4n^2 - 2n + 1 = d_n
 * 
 * sum = \sum_{i=0}^n (a_i + b_i + c_i + d_i)
 *     = \sum_{i=0}^n (16i^2 + 4n + 4)
 *     = 16 * \sum_{i=0}^n (i^2) + 4 * \sum_{i=0}^n (i) + 4(n + 1)
 *     = (8 * n(n + 1)(2n + 1) / 3) + (2n(n + 1)) + 4(n + 1)
 * 
 * result = sum - 3.
 */

#include <stdio.h>

int sum_spiral_diagonals(int n) {
    if (n % 2 != 0) {
        n--;
    }
    n /= 2;

    return 8 * (n * (n + 1) * (2 * n + 1)) / 3 + (2 * n * (n + 1)) + 4 * n + 1;
}

int main(void) {
    printf("%d\n", sum_spiral_diagonals(1001));
    return 0;
}