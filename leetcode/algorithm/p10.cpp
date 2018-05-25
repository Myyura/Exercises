/**
 * Regular Expression Matching      
 * Myyura
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