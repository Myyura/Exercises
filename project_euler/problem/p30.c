/**
 * Digit fifth powers
 * Myyura
 */

/**
 * Surprisingly there are only three numbers that can be written as the sum of 
 * fourth powers of their digits:
 * 
 * 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * 8208 = 8^4 + 2^4 + 0^4 + 8^4
 * 9474 = 9^4 + 4^4 + 7^4 + 4^4
 * As 1 = 1^4 is not a sum it is not included.
 * 
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 * 
 * Find the sum of all the numbers that can be written as the sum of fifth powers 
 * of their digits.
 */

#include <stdio.h>

/**
 * 6 * 9^5 = 354294
 * 7 * 9^5 = 413343 < 1000000
 */

int sum_digit_fifth_powers(void) {
    int sum = 0;
    for (int i = 2; i < 354294; i++) {
        int sum_powers = 0, n = i;
        for (; n > 0; n /= 10) {
            int d = n % 10;
            sum_powers += d * d * d * d * d;
        }

        if (sum_powers == i) {
            sum += i;
        }
    }

    return sum;
}

int main(void) {
    printf("%d\n", sum_digit_fifth_powers());
    return 0;
}
