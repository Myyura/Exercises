/**
 * Valid Palindrome
 * Myyura
 */

/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric 
 * characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid 
 * palindrome.
 * 
 * Example 1:
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * Example 2:
 * Input: "race a car"
 * Output: false
 */

class Solution {
public:
    bool isPalindrome(std::string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            for (; !std::isalnum(s[i]); i++) {}
            for (; !std::isalnum(s[j]); j--) {}
            if (i >= j) { break; }
            if (std::tolower(s[i]) != std::tolower(s[j])) { return false; }
        }
        return true;
    }
};