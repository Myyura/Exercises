/**
 * Digit factorials
 * Myyura
 */

/**
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * 
 * Find the sum of all numbers which are equal to the sum of the factorial of 
 * their digits.
 * 
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <stdio.h>

int fact[10] = {1 ,1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int digit_fact_sum(int n) {
    int sum = 0;
    for (; n != 0; n /= 10) { sum += fact[n % 10]; }
    return sum;
}

int digit_factorials(void) {
    int sum = 0;
    for (int i = 3; i < 999999; i++) {
        if (i == digit_fact_sum(i)) { sum += i; }
    }
    return sum;
}

int main(void) {
    printf("%d\n", digit_factorials());
    return 0;
}