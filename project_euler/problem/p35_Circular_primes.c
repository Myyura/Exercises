/**
 * Circular primes
 * Myyura
 */

/**
 * The number, 197, is called a circular prime because all rotations of the 
 * digits: 197, 971, and 719, are themselves prime.
 * 
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 
 * 73, 79, and 97.
 * 
 * How many circular primes are there below one million?
 */

// brute-force
int rotate(int n) {
    int last = n % 10;
    for (int i = n / 10; i != 0; i /= 10, last *= 10) {}
    return last + n / 10;
}

int is_prime_6k_optimization(int n) {
    if (n <= 3) {
        return 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    } else {
        for (int i = 5; i < sqrt(n) + 1; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int count_circular_primes(int upper) {
    int count = 0;
    for (int i = 2; i <= upper; i++) {
        if (is_prime_6k_optimization(i)) {
            int is_circular_prime = 1;
            for (int j = rotate(i); j != i; j = rotate(j)) {
                if (!is_prime_6k_optimization(j)) {
                    is_circular_prime = 0;
                    break;
                }
            }

            if (is_circular_prime) { count++; }
        }
    }

    return count;
}

int main(void) {
    // printf("%d\n", rotate(197));
    printf("%d\n", count_circular_primes(1000000));
    return 0;
}