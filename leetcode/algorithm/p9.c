/**
 * Palindrome Number  
 * Myyura
 */

bool isPalindrome(int x) {
    if (x < 0) {
        return 0;
    }

    int rev = 0;
    while (x != 0) {
        rev *= 10;
        rev += x % 10;
        x /= 10;
    }

    return rev == x;
}