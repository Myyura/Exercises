/* Largest prime factor */
/* Myyyura */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

int is_prime(int64_t n) {
    for (int64_t i = 2; i < sqrt(n) + 1; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

/* Enumerate */
int64_t find_max_prime_factor_enumerate(int64_t n) {
    int max_prime_factor = 2;
    for (int64_t i = 2; i < sqrt(n) + 1; i++) {
        if ((n % i == 0) && is_prime(i)) {
            max_prime_factor = i;
        }
    }

    return max_prime_factor;
}

// int64_t gcd(int64_t a, int64_t b) {
//     if (b == 0) {
//         return a;
//     } else {
//         return gcd(b, a % b);
//     }

//     return 0;
// }

int64_t gcd(int64_t a, int64_t b) {
    if (b != 0) {
        while((a %= b) && (b %= a))
            ;
    }

    return a + b;
}

/* Pollard's rho algorithm */
/* https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm */
int64_t g(int64_t x, int64_t n) {
    return (x * x + 1) % n;
}

int64_t find_factor_rho(int64_t n) {
    int64_t a = 2, b = 2;
    int64_t p = 0;
    do {
        a = g(a, n);
        b = g(g(b, n), n);
        p = gcd(llabs(b - a), n);
        if (p > 1) {
            return p;
        }
    } while (b != a);

    return 0;
}

void find_prime_factor_rho(int64_t n, int64_t factors[], int n_factors) {
    static int i = 0;

    if (n == 1) {
        return;
    } else if (is_prime(n)) {
        factors[i++] = n;
        return;
    }

    int64_t p = find_factor_rho(n);
    find_prime_factor_rho(p, factors, n_factors);
    find_prime_factor_rho(n / p, factors, n_factors);
}

int64_t find_max_prime_factor_rho(int64_t n) {
    int64_t factors[1000] = {0};
    find_prime_factor_rho(n, factors, 1000);

    int64_t max_prime_factor = 2;
    for (int i = 0; i < 1000; i++) {
        if (factors[i] > max_prime_factor) {
            max_prime_factor = factors[i];
        }
    }

    return max_prime_factor;
}

int main(void) {
    printf("%lld\n", find_max_prime_factor_enumerate(600851475143));
    printf("%lld\n", find_max_prime_factor_rho(600851475143));
    return 0;
}