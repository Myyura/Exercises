/**
 * Score of Parentheses
 * Myyura
 */

/**
 * Weekly contest 90
 * Given a balanced parentheses string S, compute the score of the string based 
 * on the following rule:
 * - () has score 1
 * - AB has score A + B, where A and B are balanced parentheses strings.
 * - (A) has score 2 * A, where A is a balanced parentheses string.
 *  
 * 
 * Example 1:
 * Input: "()"
 * Output: 1
 * 
 * Example 2:
 * Input: "(())"
 * Output: 2
 * 
 * Example 3:
 * Input: "()()"
 * Output: 2
 * 
 * Example 4:
 * Input: "(()(()))"
 * Output: 6
 */

class Solution {
public:
    int scoreOfParentheses(std::string S) {
        std::stack<int> myStack;
        for (auto& c : S) {
            if (c == '(') {
                myStack.push(-1);
            } else {
                int curScore = 0;
                for (; myStack.top() != -1;) { 
                    curScore += myStack.top();
                    myStack.pop();
                }
                myStack.pop();
                myStack.push(curScore == 0 ? 1 : curScore * 2);
            }
        }

        int score = 0;
        for (; !myStack.empty();) { 
            score += myStack.top();
            myStack.pop();
        }
        return score;
    }
};