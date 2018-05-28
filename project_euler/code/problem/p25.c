/* 1000-digit Fibonacci number */
/* Myyura */

#include <stdio.h>
#include <math.h>

/* 
    Binet's formula : f(n) = (p^n - q^n) / sqrt(5) where p = (sqrt(5) + 1) / 2
    and q = (sqrt(5) - 1) / 2.

    log10 (f(n)) = log10 ((p^n - q^n) / sqrt(5)) (*)
    since q < 1, when n -> inf, q^n -> 0
    hence (*) = log10 (p^n / sqrt(5)) when n -> inf
              = nlog10 (p) - log10 (5) / 2
    
    Lenth(f(n)) = 1 + log10 (f(n))
*/

int n_digit_fib_number(int n) {
    return ceil((n - 1 + log10(5) / 2) / log10((sqrt(5) + 1) / 2));
}

int main(void) {
    printf("%d\n", n_digit_fib_number(1000));
    return 0;
}