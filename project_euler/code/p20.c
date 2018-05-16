/* Factorial digit sum */

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