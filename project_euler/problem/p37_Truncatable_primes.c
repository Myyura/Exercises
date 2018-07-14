/**
 * Truncatable primes
 * Myyura
 */

/**
 * Problem 37 
 * The number 3797 has an interesting property. Being prime itself, it is 
 * possible 
 * to continuously remove digits from left to right, and remain prime at each 
 * stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 
 * 379, 37, and 3.
 * 
 * Find the sum of the only eleven primes that are both truncatable from left 
 * to right and right to left.
 * 
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

int is_prime_6k_optimization(int64_t n) {
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

int is_truncatable_prime(int n) {
    int n_copy = n, digits = 1;
    for (; n_copy != 0; n_copy /= 10, digits *= 10) {
        if (!is_prime_6k_optimization(n_copy) || n_copy == 1) { return 0; }
    }

    for (n_copy = n; n_copy != 0; digits /= 10, n_copy %= digits) {
        if (!is_prime_6k_optimization(n_copy) || n_copy == 1) { return 0; }
    }

    return 1;
}

int sum_truncatable_primes(void) {
    int sum = 0;
    for (int i = 11, count = 0; count < 11; i += 2) {
        if (is_truncatable_prime(i)) { 
            sum += i; 
            count++;
        }
    }

    return sum;
}

int main(void) {
    printf("%d\n", sum_truncatable_primes());
    return 0;
}