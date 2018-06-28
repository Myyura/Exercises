/**
 * Summation of primes
 * Myyyura
 */

/**
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>

int is_prime_6k_optimization(int n) {
    // assume that n > 0
    if (n <= 3) {
        return 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    } else {
        for (int64_t i = 5; i < sqrt(n) + 1; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int64_t enumerate(int limit) {
    int64_t sum = 2;
    for (int i = 3; i < limit; i += 2) {
        sum += is_prime_6k_optimization(i) ? i : 0;
    }

    return sum;
}

// Maybe the sieve of Eratosthenes is better

int main(void) {
    printf("%lld\n", enumerate(2000000));
    return 0;
}