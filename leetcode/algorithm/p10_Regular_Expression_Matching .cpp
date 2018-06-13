/**
 * Regular Expression Matching      
 * Myyura
 */

/**
 * Given an input string (s) and a pattern (p), implement regular expression 
 * matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like
 * . or *.
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
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, 
 * by repeating 'a' once, it becomes "aa".
 * 
 * Example 3:
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * Example 4:
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore 
 * it matches "aab".
 * 
 * Example 5:
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 */

class Solution {
public:
    /**
     * Basic idea:
     * Suppose that we are checking whether the position s_i matches position
     * p_j.
     * 
     * (1) If p_j is not *, then we check s_i == p_j || p_j == '.' (since '.'
     * matches all characters) and go to the next (i++, j++).
     * 
     * (2) If p_j is a *, then there are two cases -- s_i matches p_{j - 1} or
     * not.
     *     - when s_i does not match p_{j - 1} i.e. current '*' matches zero 
     *       preceding element, we skip current '*' and its preceding element
     *       in p and check whether s[i, ... ] matches p[j + 1, ... ].
     *     - when s_i matches p_{j - 1} i.e. current '*' may match one or more
     *       preceding element, we check whether s[i + 1, ...] matches p[i, ...].
     */
    bool isMatch(std::string s, std::string p) {
        if (p.empty()) {
            return s.empty();
        }

        bool curMatched = !s.empty() && (p.at(0) == s.at(0) || p.at(0) == '.');

        if (p.size() > 1 && p.at(1) == '*') {
            return isMatch(s, p.substr(2)) || (curMatched && isMatch(s.substr(1), p));
        }
        return curMatched && isMatch(s.substr(1), p.substr(1));
    }
};