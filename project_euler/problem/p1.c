/* Multiples of 3 and 5 */
/* Myyyura */

#include <stdio.h>

int sum_multiple(int limit, int x) {
    int n_x = (limit - 1) / x;
    int sum_n_x = n_x * (n_x + 1) / 2;
    return sum_n_x * x;
}

int inclusion_exclusion(int limit) {
    return sum_multiple(limit, 3) + sum_multiple(limit, 5) - sum_multiple(limit, 15);
}

int enumerate(int limit) {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}

int main(void) {
    printf("%d %d\n", enumerate(1000), inclusion_exclusion(1000));
    return 0;
}