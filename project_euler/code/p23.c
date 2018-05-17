/* Non-abundant sums */
/* Myyyura */

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