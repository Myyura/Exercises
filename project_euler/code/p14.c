/* Longest Collatz sequence */
/* Myyyura */

#include <stdio.h>
#include <stdint.h>

int64_t collatz_seq(int64_t n) {
    return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

int64_t count_collatz_seq(int64_t n) {
    int64_t count = 2;
    for (; collatz_seq(n) != 1; count++, n = collatz_seq(n))
        ;

    return count;
}

int64_t max_collatz_seq(void) {
    int64_t max_seq = 0;
    int64_t start_number = 1;
    for (int64_t i = 1000000; i >= 1; i--) {
        int64_t cur_seq = count_collatz_seq(i);
        if (max_seq < cur_seq) {
            max_seq = cur_seq;
            start_number = i;
        }
    }

    return start_number;
}

int main(void) {
    printf("%lld\n", max_collatz_seq());
    return 0;
}