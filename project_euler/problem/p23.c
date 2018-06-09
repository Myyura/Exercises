/**
 * Non-abundant sums
 * Myyyura
 */

/**
 * A perfect number is a number for which the sum of its proper divisors is 
 * exactly equal to the number. For example, the sum of the proper divisors of 
 * 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 * 
 * A number n is called deficient if the sum of its proper divisors is less than 
 * n and it is called abundant if this sum exceeds n.
 * 
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest 
 * number that can be written as the sum of two abundant numbers is 24. By 
 * mathematical analysis, it can be shown that all integers greater than 28123 
 * can be written as the sum of two abundant numbers. However, this upper limit 
 * cannot be reduced any further by analysis even though it is known that the 
 * greatest number that cannot be expressed as the sum of two abundant numbers is 
 * less than this limit.
 * 
 * Find the sum of all the positive integers which cannot be written as the sum 
 * of two abundant numbers.
 */

#include <stdio.h>

int sum_divisors_efficient(int n) {
    int sum = 1;
    int temp_n = n;
    for (int i = 2; i <= temp_n; i++) {
        int p = 1;
        while (temp_n % i == 0) {
            p *= i;
            temp_n /= i;
        }
        sum *= (p * i - 1) / (i - 1);
    }
    return sum - n;
}

int non_abundant_sum(void) {
    int abundant[28184] = {0};
    for (int i = 1; i <= 28183; i++) {
        if (sum_divisors_efficient(i) > i) {
            abundant[i] = 1;
        }
    }

    int non_abundant[28184];
    for (int i = 0; i < 28184; i++) {
        non_abundant[i] = 1;
    }

    for (int i = 1; i <= 28183; i++) {
        for (int j = 1; j <= 28183; j++) {
            if (abundant[i] == 1 && abundant[j] == 1 && i + j <= 28183) {
                non_abundant[i + j] = 0;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= 28183; i++) {
        sum += (i * non_abundant[i]);
    }

    return sum;
}

int main(void) {
    printf("%d\n", non_abundant_sum());
    return 0;
}