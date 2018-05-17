/* Largest palindrome product */
/* Myyyura */

#include <stdio.h>

int is_palindrome(int n) {
    int ori = n, rev = 0;

    while (ori > 0) {
        rev = rev * 10 + ori % 10;
        ori /= 10;
    }

    if (rev == n) {
        return 1;
    }

    return 0;
}

int enumerate(int lb, int ub) {
    int max = -1;
    for (int i = ub; i >= lb; i--) {
        for (int j = ub; j >= i; j--) {
            if (is_palindrome(i * j) && max < i * j) {
                max = i * j;
            }
        }
    }

    return max;
}

/*
    10000 <= P <= 999999

    P = 100000a + 10000b + 1000c + 100c + 10b + a (since P is palindrome)
    -> P = 11(9091a + 910b + 100c)

    P = 10000a + 1000b + 100c + 10b + a
      = 10001a + 1010b + 100c
    GCD(10001, 1010, 100) = 1
*/

int main(void) {
    printf("%d\n", enumerate(100, 999));
    return 0;
}