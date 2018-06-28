/**
 * Longest Collatz sequence
 * Myyyura
 */

/**
 * The following iterative sequence is defined for the set of positive integers:
 * 
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 * 
 * Using the rule above and starting with 13, we generate the following sequence:
 * 
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 
 * 10 terms. Although it has not been proved yet (Collatz Problem), it is thought 
 * that all starting numbers finish at 1.
 * 
 * Which starting number, under one million, produces the longest chain?
 * 
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

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