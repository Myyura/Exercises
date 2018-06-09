/**
 * Power digit sum
 * Myyyura
 */

/**
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 */

#include <stdio.h>
#include <math.h>

/* Vertical Formular Multiplication */
int power_digit_sum(int a, int b) {
    int digits = 1 + 1000 * log10(2);
    int number[digits];

    number[0] = 1;
    for (int i = 1; i < digits; i++) {
        number[i] = 0;
    }

    for (int i = 0, cur_digits = 0; i < b; i++) {
        int carry = 0;
        for (int j = 0; j <= cur_digits; j++) {
            int product = number[j] * a + carry;
            number[j] = product % 10;
            carry = product / 10;

            cur_digits += (j == cur_digits && carry > 0);
        }
    }

    int sum = 0;
    for (int i = 0; i < digits; i++) {
        sum += number[i];
    }

    return sum;
}

int main(void) {
    printf("%d\n", power_digit_sum(2, 1000));
    return 0;
}