/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (19.54%)
 * Likes:    859
 * Dislikes: 2662
 * Total Accepted:    362.3K
 * Total Submissions: 1.8M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * Example 1:
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * Note:
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * Follow up:
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

class Solution {
public:
    /**
     * First reverse the string and then reverse every word in it. 
     * O(n) time complexity, O(1) extra space is needed (since we do it in place,
     * if we use C, then just O(1) extra space is needed).
     */
    string reverseWords(string s) {
        // delete unnecessary spaces
        int i = 0, d_space = 0;
        // leading spaces
        for (; i < s.size() && s[i] == ' '; i++, d_space++) {}
        // trailing spaces
        int real_size = s.size();
        for (; real_size > i && s[real_size - 1] == ' '; real_size--) {}
        // multiple spaces
        int w_space = 0;
        for (int j = 0; i < real_size; i++) {
            if (s[i] != ' ') {
                w_space = 0;
                s[j++] = s[i];
            } else {
                if (w_space == 0) {
                    s[j++] = s[i];
                } else {
                    d_space++;
                }
                w_space++;
            }
        }
        real_size -= d_space;

        // reverse the whole s
        for (int left = 0, right = real_size - 1; left < right; left++, right--) {
            int temp = s[left];
            s[left] = s[right];
            s[right] = temp;
        }

        // reverse every word
        for (int begin = 0, end = 0, j = 0; j < real_size; j++) {
            if (s[j] != ' ' && j < real_size - 1) {
                end++;
            } else {
                if (j == real_size - 1) { end++; }
                for (int left = begin, right = end - 1; left < right; left++, right--) {
                    int temp = s[left];
                    s[left] = s[right];
                    s[right] = temp;
                }
                begin = end = j + 1;
            }
        }
        
        return s.substr(0, real_size);
    }
};
