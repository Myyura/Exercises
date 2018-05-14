/* 10001st prime */

#include <stdio.h>
#include <stdint.h>
#include <math.h>

/*
    an integer can be represents as (6k + i) for some integer k and for
    i = -1, 0, 1, 2, 3 or 4. 2 divides 6k, (6k + 2) and (6k + 4). 3 divides
    (6k + 3).
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

int64_t the_nth_prime(int n) {
    int64_t nth_prime = 2;
    for (int i = 0; ;) {
        if (is_prime_6k_optimization(nth_prime) && ++i == n) {
            break;
        }

        nth_prime++;
    }

    return nth_prime;
}

int main(void) {
    printf("%lld\n", the_nth_prime(10001));
    return 0;
}