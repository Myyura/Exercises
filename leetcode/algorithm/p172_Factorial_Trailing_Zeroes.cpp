/**
 * Factorial Trailing Zeroes
 * Myyura
 */

/**
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * Example 2:
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * Note: Your solution should be in logarithmic time complexity.
 * 
 */

/* O(logn) */
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        // count the factor 5 of numbers in [0, n]
        for (; n > 0; n /= 5) {
            result += n / 5;
        }
        return result;
    }
};