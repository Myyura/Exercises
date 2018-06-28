/**
 * Quadratic primes
 * Myyura
 */

/**
 * Euler discovered the remarkable quadratic formula:
 * 
 * n^2 + n + 41
 * It turns out that the formula will produce 40 primes for the consecutive 
 * integer values 0≤n≤39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 
 * is divisible by 41, and certainly when n = 41, 412 + 41 + 41 is clearly 
 * divisible by 41.
 * 
 * The incredible formula n^2 − 79n + 1601 was discovered, which produces 80 primes 
 * for the consecutive values 0 ≤ n ≤ 79. The product of the coefficients, −79 and 
 * 1601, is −126479.
 * 
 * Considering quadratics of the form:
 * 
 * n^2 + an + b, where |a| < 1000 and |b| ≤ 1000
 * 
 * where |n| is the modulus/absolute value of n
 * e.g. |11| = 11 and |−4| = 4
 * Find the product of the coefficients, a and b, for the quadratic expression 
 * that produces the maximum number of primes for consecutive values of n, 
 * starting with n = 0.
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