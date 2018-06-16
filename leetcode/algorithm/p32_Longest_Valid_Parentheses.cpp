/**
 * Longest Valid Parentheses
 * Myyura
 */

/**
 * Given a string containing just the characters '(' and ')', find the length 
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * Example 2:
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 */

/**
 * Main idea: 
 * Let x[i] (i = 0, ..., len(s)) denote the the lenth of a longest valid 
 * parentheses ends at i.
 * Example: 
 * Input: "()(()))"
 * Output: x[0] = 0, x[1] = 2, x[2] = 0, x[3] = 0, x[4] = 2, x[5] = 6, x[6] = 0.
 * 
 * Since a valid parentheses can only ends at ')', all x[i] where s[i] = '('
 * shall be 0.
 * 
 * If p is a valid parentheses, then "(p)" is also a valid parentheses.
 * Example: (())
 * 
 * If p and q are two valid parentheses, then p + q is also a valid parentheses.
 * Example: () + () = ()()
 * 
 * Let i be the index of ')' in "(p)". Then the index of '(' (i.e. the left 
 * parentheses that should be matched with the right parentheses in i) in "(p)" 
 * should be i - len(p) - 1. Which gives the following equality:
 *                  x[i] = x[i - x[i] - 2] + x[i - 1] + 2;
 */
class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::vector<int> x(s.size() + 1, 0);
        int longest = 0;
        for (int i = 0, leftCount = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftCount++;
            } else if (leftCount > 0) {
                x[i + 1] = x[i - 1 - x[i]] + x[i] + 2;
                longest = longest > x[i + 1] ? longest : x[i + 1];
                leftCount--;
            }
        }
        return longest;
    }
};