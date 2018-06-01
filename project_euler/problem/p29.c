/**
 * Distinct powers
 * Myyura
 */

#include <stdio.h>

/**
 * Basic idea: 
 *  a^b = x^y -> bln(a) = yln(x)
 *  Only the case that a and x are both an exponentiation of some value e, there
 *  is an integer solution of b and y.
 *  
 *  suppose that a and x are both an exponentiation of e, i.e. a = e^p and 
 *  x = e^q.
 *  then a^b = e^pb and x^y = e^qy. hence a^b = x^y iff pb = qy.
 * 
 *  An example:
 *  2^198 = 2^2^99 = 4^99 = 2^3^66 = 8^66 = 2^6^33 = 64^33
 */

/**
 * Time complexity O(ab)
 */
int count_distinct_powers(int a, int b) {
    int max_exp = 1;
    for (int i = 2; i <= a; max_exp++, i *= 2)
        ;
    max_exp = b * max_exp + 1;

    int is_repeat[a + 1][max_exp];
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= max_exp; j++) {
            is_repeat[i][j] = -1;
        }
    }

    int i;
    for (i = 2; i * i <= a; i++) { // sqrt(a)
        for (int p = i, k = 1; p <= a; p *= i, k++) { // log(a)
            for (int j = 2; j <= b; j++) { // b
                if (is_repeat[i][k * j] != 1 && is_repeat[p][j] == -1) {
                    is_repeat[i][k * j] = 1;
                    is_repeat[p][j] = 0;
                } else if (is_repeat[i][k * j] == 1) {
                    is_repeat[p][j] = 1;
                }
            }
        }
    }

    for (; i <= a; i++) {
        for (int j = 2; j <= b; j++) {
            if (is_repeat[i][j] == -1) {
                is_repeat[i][j] = 0;
            }
        }
    }

    int result = 0;
    for (int i = 2; i <= a; i++) {
        for (int j = 2; j <= b; j++) {
            result += is_repeat[i][j] == 0 ? 1 : 0;
        }
    }

    return result;
}

int main(void) {
    printf("%d\n", count_distinct_powers(100, 100));
    return 0;
}