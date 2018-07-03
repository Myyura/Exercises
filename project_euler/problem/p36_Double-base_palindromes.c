/**
 * Double-base palindromes
 * Myyura
 */

/**
 * The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
 * 
 * Find the sum of all numbers, less than one million, which are palindromic in 
 * base 10 and base 2.
 * 
 * (Please note that the palindromic number, in either base, may not include 
 * leading zeros.)
 */

// brute-force
int demical_to_binary(int demical, char binary[]) {
    // assume that binary has enough space
    int len = 0;
    for (; demical != 0; binary[len++] = demical % 2, demical /= 2) {}
    return len;
}

int is_palindrome_demical(int n) {
    int ori = n, rev = 0;
    while (ori > 0) {
        rev = rev * 10 + ori % 10;
        ori /= 10;
    }
    if (rev == n) { return 1; }

    return 0;
}

int is_palindrome_binary(char *binary, int len) {
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (binary[i] != binary[j]) { return 0; }
    }
    return 1;
}

int sum_double_base_palindromes(int upper) {
    int max_len = log(upper) / log(2) + 2, sum = 0;;
    char binary[max_len];
    for (int i = 1; i <= upper; i++) {
        if (is_palindrome_demical(i)) {
            int len = demical_to_binary(i, binary);
            sum += is_palindrome_binary(binary, len) ? i : 0;
        }
    }

    return sum;
}

int main(void) {
    printf("%d\n", sum_double_base_palindromes(1000000));
    return 0;
}