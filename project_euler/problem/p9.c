/**
 * Special Pythagorean triplet
 * Myyyura
 */

/**
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * 
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <stdio.h>

int enumerate(int n) {
    for (int c = n; c > 0; c--) {
        for (int b = n - c; b > 0; b--) {
            int a = n - b - c;
            if (a > 0 && a * a + b * b == c * c) {
                return a * b * c;
            }
        }
    }

    return -1;
}

int main(void) {
    printf("%d\n", enumerate(1000));
    return 0;
}