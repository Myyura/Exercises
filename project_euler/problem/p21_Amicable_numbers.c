/**
 * Amicable numbers
 * Myyyura
 */

/**
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than 
 * n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and 
 * each of a and b are called amicable numbers.
 * 
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 
 * and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 
 * and 142; so d(284) = 220.
 * 
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <stdio.h>
#include <string.h>

int sum_divisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        sum += (n % i == 0 ? i : 0);
    }

    return sum;
}

/**
 * Let p be a prime and a be an integer > 0.
 * 
 * Let n = p^a. Then d(n) = 1 + p + p^2 + ... + p^a = (p^(a + 1) - 1) / (p - 1).
 * When n = p^a q^b r^c ... where p, q, r, ... are distinct prime numbers and a,
 * b, c, ... are positive integers.
 * 
 * d(n) = d(p^a)d(q^b)d(r^c)...
 * https://en.wikipedia.org/wiki/Divisor_function
 */
int sum_divisors_efficient(int n) {
    int sum = 1;
    int temp_n = n;
    for (int i = 2; i <= n; i++) {
        int p = 1;
        while (n % i == 0) {
            p *= i;
            n /= i;
        }
        sum *= (p * i - 1) / (i - 1);
    }
    return sum - temp_n;
}

int sum_of_amicable_numbers_under_n(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int di = sum_divisors_efficient(i);
        if (di > i && sum_divisors_efficient(di) == i) {
            sum += (di + i);
        }
    }

    return sum;
}

int main(void) {
    printf("%d\n", sum_of_amicable_numbers_under_n(10000));
    return 0;
}