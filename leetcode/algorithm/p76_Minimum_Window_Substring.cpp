/**
 * Minimum Window Substring
 * Myyura
 */

/**
 * Given a string S and a string T, find the minimum window in S which will 
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the  * empty string "".
 * If there is such window, you are guaranteed that there will always be only 
 * one unique minimum window in S.
 */

class Solution {
public:
    /**
     * Basic idea:
     * Let t(c) denote the number of letter c in string t.
     * Let s[i][j](c) denote the number of letter c in string s[i..j].
     * 
     * If for all c in t, s[i][j](c) = t(c), then we know s[i..j] is a valid
     * window, we need compare it with the minimum window we have found so far,
     * 
     * If there is some c in s[i][j] with s[i][j](c) > t(c), then we know that
     * it is possible to move i s.t. s[i..j] is still a valid window but with
     * shorter length. The importance is, when we change i, we should ensure
     * that any letter c (in both s[i..j] and t) with s[i][j](c) <= t(c) is still
     * in s[i..j] after changing.
     */
    std::string minWindow(std::string s, std::string t) {
        std::unordered_map<char, int> tCharMap, isMatched;
        for (auto& c : t) { 
            if (tCharMap.count(c) == 0) { tCharMap[c] = 1; }
            else { tCharMap[c]++; } 
        }
        
        int start = -1, minWindow = s.size() + 1, minWindowStart = -1;
        for (int i = 0; i < s.size(); i++) {
            if (tCharMap.count(s[i]) == 1) {
                if (start == -1) { start = i; }
                
                tCharMap[s[i]]--;
                if (tCharMap[s[i]] <= 0) { isMatched[s[i]] = 1; }
                if (tCharMap[s[i]] > 0) { continue; }

                for (; ; start++) {
                    if (tCharMap.count(s[start]) == 0) { continue; }
                    if (tCharMap[s[start]] + 1 <= 0) { tCharMap[s[start]]++; }
                    else { break; }
                }
            }

            if (isMatched.size() == tCharMap.size() && minWindow >= i - start + 1) {
                minWindowStart = start;
                minWindow = i - start + 1;
            }
        }
        if (minWindowStart == -1) { return ""; }
        
        return s.substr(minWindowStart, minWindow);
    }
};