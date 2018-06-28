/**
 * Reciprocal cycles
 * Myyura
 */

/**
 * A unit fraction contains 1 in the numerator. The decimal representation of 
 * the unit fractions with denominators 2 to 10 are given:
 * 
 * 1/2	= 	0.5
 * 1/3	= 	0.(3)
 * 1/4	= 	0.25
 * 1/5	= 	0.2
 * 1/6	= 	0.1(6)
 * 1/7	= 	0.(142857)
 * 1/8	= 	0.125
 * 1/9	= 	0.(1)
 * 1/10	= 	0.1
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be 
 * seen that 1/7 has a 6-digit recurring cycle.
 * 
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle 
 * in its decimal fraction part.
 */

#include <stdio.h>
#include <stdint.h>

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

// What I learned in primary school about division
int reciprocal_cycles_length(int n) {
    int lenth = 1;
    for (int remainder = -1, denominator = 10; remainder != 0 && remainder != 1;) {
        remainder = denominator % n;
        denominator = remainder * 10;
        lenth++;
    }

    return lenth;
}

int max_reciprocal_cycles_length_below_n(int n) {
    int max_lenth = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime_6k_optimization(i)) {
            int lenth = reciprocal_cycles_length(i);
            max_lenth = lenth > max_lenth ? lenth : max_lenth;
        }
    }

    return max_lenth;
}

int main(void) {
    printf("%d\n", reciprocal_cycles_length(7));
    printf("%d\n", max_reciprocal_cycles_length_below_n(1000));
    return 0;
}