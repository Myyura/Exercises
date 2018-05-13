/* Highly divisible triangular number */

#include <stdio.h>

/* 
    Divisor function 
    https://en.wikipedia.org/wiki/Divisor_function
*/

/* 
    Let n = p^a q^b r^c ... where p, q, r, ... are distinct prime numbers and a,
    b, c, ... are positive integers.

    Then the number of divisors d(n) of n is (a + 1)(b + 1)(c + 1)...

    Consider the case that n' = p^a q^b.
    The divisors of n would be
        1   p    p^2    ... p^a
        q   qp   qp^2   ... qp^a
        q^2 q^2p q^2p^2 ... q^2p^a
        ...
        q^b q^bp q^bp^2 ... q^bp^a
    Since p != q, easy to see that all the divisors are distinct.
    Hence d(n') = (a + 1)(b + 1).

    With this kind of idea, it is not difficult to prove that
        d(n) = (a + 1)(b + 1)(c + 1)...
*/

/*
    With the fact that two numbers n and n + 1 have no prime divisors in 
    common, then d(triangle(n)) = d(n / 2) * d(n + 1) where we suppose that
    n % 2 == 0.
*/

int triangle_number(int n) {
    return n * (n + 1) / 2;
}

int num_divisors(int n) {
    int dn = 1;

    for (int d = 2; d <= n; d++) {
        int count = 0;
        for (; n % d == 0; n /= d, count++)
            ;

        dn *= (count + 1);
    }

    return dn;
}

int triangle_with_n_divisors(int n) {
    for (int i = 1; ; i++) {
        int n1 = i % 2 == 0 ? i / 2 : i;
        int n2 = i % 2 == 0 ? i + 1 : (i + 1) / 2;

        int d1 = num_divisors(n1);
        int d2 = num_divisors(n2);

        if (d1 * d2 > n) {
            return triangle_number(i);
        }
    }

    return -1;
}

int main(void) {
    printf("%d\n", triangle_with_n_divisors(500));
    return 0;
}
