/**
 * Reverse Integer  
 * Myyura
 */

/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * Input: 123
 * Output: 321
 * 
 * Example 2:
 * Input: -123
 * Output: -321
 * 
 * Example 3:
 * Input: 120
 * Output: 21
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers within 
 * the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, 
 * assume that your function returns 0 when the reversed integer overflows.
 */

int reverse(int x) {
    long int result = 0;
    int flag = x > 0 ? 1 : -1;
    x *= flag;
    while (x != 0) {
        result *= 10;
        result += x % 10;
        x /= 10;
    }

    if (result > INT_MAX || result < INT_MIN) {
        return 0;
    }
    
    return result * flag;
}