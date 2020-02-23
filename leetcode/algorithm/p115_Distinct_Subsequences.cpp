/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (36.64%)
 * Likes:    956
 * Dislikes: 48
 * Total Accepted:    123.6K
 * Total Submissions: 336.2K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * Example 1:
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 * 
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * Example 2:
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 * 
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 */

class Solution {
public:
    /* DP, O(m^2 * n), inefficient but accepted */
    // int numDistinct(std::string s, std::string t) {
    //     // sub_problem[i][j] = #distinct subseqs of t[0...j] in s[0...i]
    //     // sp[i][j] = \sum sp[0...i-1][j-1] if s[i] == t[j]
    //     // sp[i][j] = 0

    //     // in test case 61, the result is larger than 2^31 - 1
    //     std::vector<std::vector<long>> sp(s.size(), std::vector<long> (t.size()));
    //     for (int i = 0; i < s.size(); i++) {
    //         sp[i][0] = s[i] == t[0];
    //     }

    //     for (int j = 1; j < t.size(); j++) {
    //         sp[0][j] = 0;
    //     }

    //     for (int i = 1; i < s.size(); i++) {
    //         for (int j = 1; j < t.size(); j++) {
    //             sp[i][j] = 0;
    //             if (t[j] == s[i]) {
    //                 for (int k = 0; k < i; k++) {
    //                     sp[i][j] += sp[k][j - 1];
    //                 }
    //             }
    //         }
    //     }

    //     int result = 0;
    //     for (int i = 0; i < s.size(); i++) {
    //         result += sp[i][t.size() - 1];
    //     }

    //     return result;
    // }

    /* Refined version, O(mn), accepted */
    int numDistinct(std::string s, std::string t) {
        std::vector<std::vector<long>> sp(s.size() + 1, std::vector<long> (t.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++) {
            // t = ""
            sp[i][0] = 1;
        }

        for (int i = 1; i <= s.size(); i++)  {
            for (int j = 1; j <= t.size(); j++) {
                // two cases, if we use s[i - 1] or not
                sp[i][j] += sp[i - 1][j];

                if (s[i - 1] == t[j - 1]) {
                    sp[i][j] += sp[i - 1][j - 1];
                }
            }
        }

        return sp[s.size()][t.size()];
    }
};
