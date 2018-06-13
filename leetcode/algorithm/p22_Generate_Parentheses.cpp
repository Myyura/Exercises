/**
 * Generate Parentheses
 * Myyura
 */

/**
 * Given n pairs of parentheses, write a function to generate all combinations 
 * of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */

/**
 * Basic idea:
 * Let s be a parentheses string. 
 * 1. Only when the number of left parenthesis is smaller than n we can add a 
 * left parenthesis at the end of s.
 * 2. Only when the number of left parenthesis is larger than the number of 
 * right parenthesis we can add a right parenthesis at the end of s.
 */

class Solution {
public:
    void generateParenthesis(std::string s, int left, int n, std::vector<std::string>& r) {
        if (s.size() == 2 * n) {
            r.push_back(s);
            return;
        }

        if (left < n) {
            generateParenthesis(s + '(', left + 1, n, r);
        }

        if (left > s.size() - left) {
            generateParenthesis(s + ')', left, n, r);
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generateParenthesis("", 0, n, result);
        return result;
    }
};