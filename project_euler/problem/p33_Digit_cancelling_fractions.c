/**
 * Digit cancelling fractions
 * Myyura
 */

/**
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician 
 * in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which 
 * is correct, is obtained by cancelling the 9s.
 * 
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 * 
 * There are exactly four non-trivial examples of this type of fraction, less 
 * than one in value, and containing two digits in the numerator and denominator.
 * 
 * If the product of these four fractions is given in its lowest common terms, 
 * find the value of the denominator.
 */

/**
 * Let the resulting nominator and denominator be n and d with 1 <= n < d <= 9.
 * Let the variable to be canceled be c with 1 <= c <= 9.
 * 
 * Then we have following four cases:
 *  - (10n + c) / (10d + c) = n / d     
 *  - (10c + n) / (10c + d) = n / d     
 *  - (10c + n) / (10d + c) = n / d     
 *  - (10n + c) / (10c + d) = n / d     
 * 
 * Hence
 *  - 10dn + cd = 10dn + cn => d = n                    (1)
 *  - 10cd + dn = 10cn + dn => d = n                    (2)
 *  - 10cd + dn = 10dn + cn => 9d(n - c) = c(d - n)     (3)
 *  - 10dn + cd = 10cn + dn => 9n(c - d) = c(d - n)     (4)
 * 
 * With the fact that n < d, we know that case (1) and (2) has no solution.
 * 
 * Also, the right hand side of (3) are positive since d > n. 
 * Hence 9d(n - c) > 0. Hence n > c.
 * Rearrange the equation (3), then we have
 *      n - c = (c / 9) - (cn / 9d) < 1
 * Hence case (3) also has no solution.
 * 
 * For case (4) we have
 *      n(c - d) = c(d - n) / 9
 * Since c(d - n) shall be divisible by 9, c must be one of 3, 6 or 9.
 * 
 * If c = 3, then d - n shall be 3 or 6. With the fact that c - d > 0, we have
 * that n < d < c = 3. Hence no solution.
 * 
 * If c = 6, then same analysis as c = 3 we have that d < n < 6 and d - n = 3.
 * Which gives two solutions n = 1, d = 4 and n = 2, d = 5.
 * 
 * If c = 9, then by some calculation we have that n = d / (10 - d) > 0, which
 * give two solutions d = 5 and d = 8.
 * 
 * Hence the four non-trivial solutions are
 *      - 16 / 64 = 1 / 4
 *      - 26 / 65 = 2 / 5
 *      - 19 / 95 = 1 / 5 and
 *      - 49 / 98 = 4 / 8
 */

#include <stdio.h>

int main(void) {
    printf("%d\n", 100);
    return 0;
}