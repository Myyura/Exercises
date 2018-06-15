/**
 * Plus One
 * Myyura
 */

/**
 * Given a non-empty array of digits representing a non-negative integer, plus 
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of 
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the 
 * number 0 itself.
 * 
 * Example 1:
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * Example 2:
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 */

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> result(digits);
        result[result.size() - 1]++;
        int carry = 0;
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] += carry;
            carry = result[i] / 10;
            result[i] %= 10;
        }
        
        if (carry != 0) { result.insert(result.begin(), carry); }
        return result;
    }
};