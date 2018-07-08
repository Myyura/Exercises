/**
 * Prime Palindrome
 * Myyura
 */

/**
 * Find the smallest prime palindrome greater than or equal to N.
 *
 * Recall that a number is prime if it's only divisors are 1 and itself, and it 
 * is greater than 1. 
 * 
 * For example, 2,3,5,7,11 and 13 are primes.
 * 
 * Recall that a number is a palindrome if it reads the same from left to right 
 * as it does from right to left. 
 * 
 * For example, 12321 is a palindrome.
 * 
 * Example 1:
 * Input: 6
 * Output: 7
 * 
 * Example 2:
 * Input: 8
 * Output: 11
 * 
 * Example 3:
 * Input: 13
 * Output: 101
 * 
 * Note:
 * 1 <= N <= 10^8
 */

int isPrime(int n) {
    // assume that n > 0
    if (n <= 3) {
        return 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    } else {
        for (int i = 5; i < sqrt(n) + 1; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return 0;
            }
        }
    }

    return 1;
}
    
int primePalindrome(int N) {
    if (N == 1 || N == 2) { return 2; }
    int isFound = 0;
    
    /**
     * There is a formula that can help us generate some palindrome numbers, see
     * https://math.stackexchange.com/questions/1179426/is-there-a-formula-that-verifys-if-a-number-is-a-palindromic-number
     */
    if (0 < N && N < 10) {
        for (int i = 1; i <= 9; i++) {
            if (i >= N && isPrime(i)) { return i; }
            isFound = 1;
        }
    }
        
    if (isFound || 10 <= N && N < 100) {
        for (int i = 1; i <= 9; i++) {
            if (11 * i >= N && isPrime(11 * i)) { return 11 * i; }
            isFound = 1;
        }
    }
        
    if (isFound || 100 <= N && N < 1000) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                int palindrome = 101 * i + 10 * j;
                if (palindrome >= N && isPrime(palindrome)) { return palindrome; }
                isFound = 1;
            }
        }
    }
        
    if (isFound || 1000 <= N && N < 10000) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                int palindrome = 1001 * i + 110 * j;
                if (palindrome >= N && isPrime(palindrome)) { return palindrome; }
                isFound = 1;
            }
        }
    }
        
    if (isFound || 10000 <= N && N < 100000) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    int palindrome = 10001 * i + 1010 * j + 100 * k;
                    if (palindrome >= N && isPrime(palindrome)) { return palindrome; }
                    isFound = 1;
                }
            }
        }
    }
        
    if (isFound || 100000 <= N && N < 1000000) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    int palindrome = 100001 * i + 10010 * j + 1100 * k;
                    if (palindrome >= N && isPrime(palindrome)) { return palindrome; }
                    isFound = 1;
                }
            }
        }
    }
        
    if (isFound || 1000000 <= N && N < 10000000) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    for (int p = 0; p <= 9; p++) {
                        int palindrome = 1000001 * i + 100010 * j + 10100 * k + 1000 * p;
                        if (palindrome >= N && isPrime(palindrome)) { return palindrome; }
                        isFound = 1;
                    }
                }
            }
        }
    }
        
    if (isFound || 10000000 <= N && N < 100000000) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    for (int p = 0; p <= 9; p++) {
                        int palindrome = 10000001 * i + 1000010 * j + 100100 * k+ 11000 * p;
                        if (palindrome >= N && isPrime(palindrome)) { return palindrome; }
                        isFound = 1;
                    }
                }
            }
        }
    }
        
    if (isFound || 100000000 <= N) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    for (int p = 0; p <= 9; p++) {
                        for (int q = 0; q <= 9; q++) {
                            int palindrome = 100000001 * i + 10000010 * j + 1000100 * k + 101000 * p + 10000 * q;
                            if (palindrome >= N && isPrime(palindrome)) { return palindrome; }
                        }
                    }
                }
            }
        }
    }

    return -1;
}