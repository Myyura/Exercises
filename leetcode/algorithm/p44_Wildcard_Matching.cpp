/**
 * Wildcard Matching
 * Myyura
 */

/**
 * Given an input string (s) and a pattern (p), implement wildcard pattern 
 * matching with support for '?' and '*'.
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like 
 * ? or *.
 * 
 * Example 1:
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * Example 2:
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * 
 * Example 3:
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not 
 * match 'b'.
 * 
 * Example 4:
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*' 
 * matches the substring "dce".
 * 
 * Example 5:
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 */

class Solution {
public:
    /**
     * Basic idea: 
     * Suppose that we are comparing s[i] with a star in p[j].
     * If s[i, ...] matches p[j + 1, ...], then we are lucky, it finishes.
     * Otherwise we should skip the character in s[i] (s[i] now matches the star),
     * and check if s[i + 1, ...] matches p[j + 1, ...]. And then repeats.
     * 
     * Recursive version does not work well, TLE.
     */
    bool isMatch(std::string s, std::string p) {
        if (p.empty()) { return s.empty(); }
        if (s.empty()) {
            for (int i = 0; i < p.size(); i++) {
                if (p.at(i) != '*') { return false; }
            }
            return true;
        }
        int lastStar = -1;
        for (int i = 0; i < p.size() && p.at(i) == '*'; i++) { 
            lastStar = std::max(i, lastStar); 
        }

        if (lastStar != -1) {
            bool flag = false;
            for (int i = 0; i <= s.size(); i++) {
                flag = flag || isMatch(s.substr(i), p.substr(lastStar + 1));
            }
            return flag;
        }
        bool curMatched = !s.empty() && (p.at(0) == s.at(0) || p.at(0) == '?');
        return curMatched && isMatch(s.substr(1), p.substr(1));
    }

    // O(mn) the worst case.
    bool isMatch(std::string s, std::string p) {
        int lastStar = -1, lastMactch, j = 0;
        for (int i = 0; i < s.size();) {
            if (j < p.size() && (p.at(j) == s.at(i) || p.at(j) == '?')) {
                i++;
                j++;
            } else if (j < p.size() && p.at(j) == '*') {
                lastStar = j;
                lastMactch = i;
                j++;
            } else if (lastStar != -1) {
                j = lastStar + 1;
                lastMactch++;
                i = lastMactch;
            } else {
                return false;
            }
        }

        for (; j < p.size() && p.at(j) == '*'; j++)
            ;
        return j == p.size();
    }
};