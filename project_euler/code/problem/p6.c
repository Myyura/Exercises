/* Sum square difference */
/* Myyyura */

#include <stdio.h>

/*
    1 + 2 + ... + n = n(n + 1) / 2
*/

/* 
    1 + 3 + 5 + ... + 2n-1 = 2n * n / 2 = n^2

    \sum_i i^2 = n * 1 + (n - 1) * 3 + (n - 2) * 5 + ... + 1 * (2n - 1)
               = (1 + 3 + 5 + ... + 2n-1) * -
                 (0 * 1 + 1 * 3 + 2 * 5 + ... + (n - 1) * (2n -1))
               = n^3 - \sum_i {(i - 1) * (2i - 1)}
               = n^3 - 2 * \sum_i {(i - 1)^2} - \sum_i {(i - 1)}
               = n^3 - 2 * \sum_i {i^2} + 2n^2 - n(n-1)/2
    3 * \sum_i i^2 = n^3 + 2n^2 - n(n - 1) / 2

    -> \sum_i i^2 = n(n + 1)(2n + 1) / 6
*/

int sum_square_difference(int n) {
    return n * (n + 1) * n * (n + 1) / 4 - n * (n + 1) * (2 * n + 1) / 6;
}

int main(void) {
    printf("%d\n", sum_square_difference(100));
    return 0;
}    