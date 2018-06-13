/**
 * Longest Palindromic Substring  
 * Myyura
 */

/**
 * Given a string s, find the longest palindromic substring in s. You may assume 
 * that the maximum length of s is 1000.
 * 
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * Example 2:
 * Input: "cbbd"
 * Output: "bb"
 */

class Solution {
public:
    bool isPalindrome(std::string s, int begin, int end) {
        for (int i = begin, j = end; i <= j; i++, j--) {
            if (s.at(i) != s.at(j)) {
                return false;
            }
        }

        return true;
    }
    
    // Brute-force but accepted
    std::string longestPalindromeBF(std::string s) {
        int start = 0, maxLen = 1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = s.size() - 1; j > i; j--) {
                if (s.at(j) != s.at(i)) {
                    continue;
                }

                if (maxLen < j - i + 1 && isPalindrome(s, i, j)) {
                    maxLen = j - i + 1;
                    start = i;
                    break;
                }
            }
        }

        return s.substr(start, maxLen);
    }
    
    /*
     *  An DP algorithem.
     *  isPalindrome[i][j] = true means that s_i ... s_j is palindrome.
     * 
     *  Then isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && s_i == s_j.
     *       Ex. "#aa*" is palindrome if "aa" is palindrome and # == *.
     *   
     *  Base: (1) Every single character is palindrome;
     *        (2) "**" is palindrome.
     */
    std::string longestPalindromeDP(std::string s) {
        bool isPalindrome[s.size()][s.size()];

        int start = 0, maxLen = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            isPalindrome[i][i] = true;
            isPalindrome[i][i + 1] = s.at(i) == s.at(i + 1);
            if (isPalindrome[i][i + 1]) {
                start = i;
                maxLen = 2;
            }
        }
        isPalindrome[s.size() - 1][s.size() - 1] = true;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 2; j < s.size(); j++) {
                isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && s.at(i) == s.at(j);
                if (isPalindrome[i][j] && maxLen < j - i + 1) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};