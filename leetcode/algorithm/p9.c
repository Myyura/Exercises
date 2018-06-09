/**
 * Palindrome Number  
 * Myyura
 */

/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when 
 * it reads the same backward as forward.
 * 
 * Example 1:
 * Input: 121
 * Output: true
 * 
 * Example 2:
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 
 * 121-. Therefore it is not a palindrome.
 * 
 * Example 3:
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
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