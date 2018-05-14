/* Special Pythagorean triplet */

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