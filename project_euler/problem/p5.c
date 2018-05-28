/* Smallest multiple */
/* Myyyura */

#include <stdio.h>
#include <stdint.h>

/* Find the LCM of 1..20 */
int64_t gcd(int64_t a, int64_t b) {
    if (b != 0) {
        while((a %= b) && (b %= a))
            ;
    }

    return a + b;
}

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

int64_t find_lcm_of_range(int64_t lb, int64_t ub) {
    int64_t result = lcm(lb, lb + 1);
    for (int64_t i = lb + 2; i <= ub; i++) {
        result = lcm(result, i);
    }

    return result;
}

/*
    prime numbers in [1, 20] : 2, 3, 5, 7, 11, 13, 17, 19;
    every prime number will be a factor of the answer.

    20 = 2 * 2 * 5;
    18 = 2 * 3 * 3;
    16 = 2 * 2 * 2 * 2;
    15 = 3 * 5;
    14 = 2 * 7;
    12 = 2 * 2 * 3;
    10 = 2 * 5;
    9 = 3 * 3;
    8 = 2 * 2 * 2;
    6 = 2 * 3;
    4 = 2 * 2;

    We need four 2 (for 16) and one more 3 (for 18).
    2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * (2 * 2 * 2 * 3) = 232792560
*/

int main(void) {
    printf("%lld\n", find_lcm_of_range(1, 20));
    printf("%d\n", 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * (2 * 3 * 2 * 2));
    return 0;
}