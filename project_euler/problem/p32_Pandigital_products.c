/**
 * Pandigital products
 * Myyura
 */

/**
 * We shall say that an n-digit number is pandigital if it makes use of all the 
 * digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 
 * through 5 pandigital.
 * 
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing 
 * multiplicand, multiplier, and product is 1 through 9 pandigital.
 * 
 * Find the sum of all products whose multiplicand/multiplier/product identity 
 * can be written as a 1 through 9 pandigital.
 * 
 * HINT: Some products can be obtained in more than one way so be sure to only 
 * include it once in your sum.
 */

#include <stdio.h>
#include <stdlib.h>

int char_compare(const void *a, const void *b) {
    if (*(char *)a < *(char *)b) { return -1; }
    if (*(char *)a == *(char *)b) { return 0; }
    return 1;
}

int is_pandigital(char *s, int n) {
    qsort(s, n, sizeof(char), char_compare);
    for (int i = 0; i < n; i++) {
        if (s[i] != i + 1 + '0') { return 0; }
    }
    return 1;
}

int is_pandigital_products(int n) {
    for (int i = 1; i * i <= n; i++) {
        char s[10];
        sprintf(s, "%d", n);
        if (n % i == 0) {
            char si[10], sni[10];
            sprintf(si, "%d", i);
            sprintf(sni, "%d", n / i);

            /**
             * The following part combines s, si and sni.
             * Since we wanna find the products whose multiplicand/multiplier/
             * product identity can be written as a 1 through 9 pandigital, if 
             * the concatenation of s (product), si (multiplicand) and sni
             * (multiplier) should have exactly 9 digits and be pandigital.
             */
            int s_len = 0;
            for (; s[s_len] != '\0'; s_len++) { }
            for (int j = 0; si[j] != '\0'; j++) { s[s_len++] = si[j]; }
            for (int j = 0; sni[j] != '\0'; j++) { s[s_len++] = sni[j]; }
            s[s_len] = '\0';

            if (s_len == 9 && is_pandigital(s, s_len)) { return 1; }
        }
    }

    return 0;
}

int sum_pandigital_products(void) {
    int sum = 0;
    for (int i = 1000; i < 10000; i++) {
        sum += is_pandigital_products(i) ? i : 0;
    }
    return sum;
}

int main(void) {
    printf("%d\n", sum_pandigital_products());
    return 0;
}