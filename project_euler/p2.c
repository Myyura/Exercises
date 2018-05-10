/* Even Fibonacci numbers */

#include <stdio.h>

/*
    Note that the first two fibonacci number is 1 (odd) and 1 (odd).
    Then,
            odd + odd = even; (o o e)
            even + odd = odd; o (o e o)
            odd + even = odd; o o (e o o)
            odd + odd = even; o o e (o o e)
*/

int sum_3rd(int limit) {
    int sum = 0;
    int fib_1st = 1, fib_2nd = 1, fib_3rd = 2;
    while (fib_3rd < limit) {
        sum += fib_3rd;
        fib_1st = fib_2nd + fib_3rd;
        fib_2nd = fib_3rd + fib_1st;
        fib_3rd = fib_1st + fib_2nd;
    }

    return sum;
}

int enumerate(int limit) {
    int sum = 0;
    int fib_pre = 1, fib_now = 1;
    while (fib_now < limit) {
        int temp = fib_now;
        fib_now = fib_pre + fib_now;
        fib_pre = temp;

        if (fib_now % 2 == 0) {
            // printf("%d \n", fib_now);
            sum += fib_now;
        }
    }

    return sum; // Do not forget the first even fibonacci number
}

int main(void) {
    printf("%d %d\n", enumerate(4000000), sum_3rd(4000000));
    return 0;
}