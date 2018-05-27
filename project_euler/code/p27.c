/**
 * Quadratic primes
 * Myyura
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

// from problem 10
int is_prime_6k_optimization(int n) {
    if (n <= 3) {
        return 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    } else {
        for (int64_t i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int64_t fn(int n, int a, int b) {
    return n * n + a * n + b;
}

int count_consecutive_prime(int a, int b) {
    for (int n = 0; ; n++) {
        if (!is_prime_6k_optimization(llabs(fn(n, a, b)))) {
            return n;
        }
    }

    return -1;
}

// Brute-force
int max_coefproduct_quadratic_primes(int au, int bu) {
    int max_product = 0, max_count = 0;
    for (int a = -au + 1; a < au; a++) {
        for (int b = -bu; b <= bu; b++) {
            int current_cout = count_consecutive_prime(a, b);
            if (max_count < current_cout) {
                max_count = current_cout;
                max_product = a * b;
            }
        }
    }

    return max_product;
}

int main(void) {
    printf("%d\n", max_coefproduct_quadratic_primes(1000, 1000));
    return 0;
}