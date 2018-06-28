/**
 * 1000-digit Fibonacci number
 * Myyura
 */

/**
 * The Fibonacci sequence is defined by the recurrence relation:
 * 
 * Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 * Hence the first 12 terms will be:
 * 
 * F1 = 1
 * F2 = 1
 * F3 = 2
 * F4 = 3
 * F5 = 5
 * F6 = 8
 * F7 = 13
 * F8 = 21
 * F9 = 34
 * F10 = 55
 * F11 = 89
 * F12 = 144
 * The 12th term, F12, is the first term to contain three digits.
 * 
 * What is the index of the first term in the Fibonacci sequence to contain 1000 
 * digits?
 */

#include <stdio.h>
#include <math.h>

/**
 * Binet's formula : f(n) = (p^n - q^n) / sqrt(5) where p = (sqrt(5) + 1) / 2
 * and q = (sqrt(5) - 1) / 2.
 *
 * log10 (f(n)) = log10 ((p^n - q^n) / sqrt(5)) (*)
 * since q < 1, when n -> inf, q^n -> 0
 * hence (*) = log10 (p^n / sqrt(5)) when n -> inf
 *           = nlog10 (p) - log10 (5) / 2
 * 
 * Lenth(f(n)) = 1 + log10 (f(n))
 */

int n_digit_fib_number(int n) {
    return ceil((n - 1 + log10(5) / 2) / log10((sqrt(5) + 1) / 2));
}

int main(void) {
    printf("%d\n", n_digit_fib_number(1000));
    return 0;
}