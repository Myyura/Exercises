/**
 * Decode Ways
 * Myyura
 */

/**
 * A message containing letters from A-Z is being encoded to numbers using 
 * the following mapping:
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given a non-empty string containing only digits, determine the total number 
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * Example 2:
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" 
 * (2 2 6).
 */

class Solution {
public:
    /**
     * Basic idea:
     * D(s): number of ways to decode s.
     * D(?*?0?*?) = D(?*?)D(?*?), where ? is a non-zero number.
     * 
     * When we have a new non-zero digit (for example, 1) in the last of a 
     * string s = "?*?", then either the new digit itself is decoded as a letter
     * or the new digit with the last digit of s are decoded as a letter.
     * Hence we have D((?*?1) = D(?*?) + D(?*).
     * 
     * Based on these two observations, we have the following solution.
     */
    int numDecodings(std::string s) { 
        int dp[s.size()], result = 1, start = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (i - 1 == start || s[i - 1] > '2') { return 0; }
                if (i == start + 2) { dp[i] = 1 && s[i - 1] <= '2'; }
                else { dp[i] = dp[i - 2]; }
                start = i, result *= dp[i];
            } else {
                if (i - 1 == start) { dp[i] = 1; }
                else {
                    int flag = s[i] <= '6' && s[i - 1] <= '2' || s[i - 1] == '1';
                    if (i == start + 2) { dp[i] = dp[i - 1] + flag; } 
                    else { dp[i] = dp[i - 1] + dp[i - 2] * flag; }
                }
            }
        }
        
        if (start != s.size() - 1) { result *= dp[s.size() - 1]; }
        return result;
    }
};