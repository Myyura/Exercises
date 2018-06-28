/**
 * Factorial digit sum
 * Myyyura
 */

/**
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 * 
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * 
 * Find the sum of the digits in the number 100!
 */

#include <stdio.h>

#define MAX_DIGITS 10000

int factorial_digit_sum(int n) {
    int fact[MAX_DIGITS] = {0};

    fact[0] = 1;
    int digits = 0;
    for (int i = 1; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j <= digits; j++) {
            int product = fact[j] * i + carry;
            fact[j] = product % 10;
            carry = product / 10;

            digits += (j == digits && carry > 0);
        }
    }

    int sum = 0;
    for (int i = 0; i <= digits; i++) {
        sum += fact[i];
    }

    return sum;
}

int main(void) {
    printf("%d\n", factorial_digit_sum(100));
    return 0;
}