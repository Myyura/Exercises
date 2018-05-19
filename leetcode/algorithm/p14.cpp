/**
 * Longest Common Prefix          
 * Myyura
 */

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        std::string prefix = strs[0];
        for (int i = 0; ; i++) {
            for (auto &it : strs) {
                if (i == it.size() || prefix[i] != it[i]) {
                    return prefix.substr(0, i);
                }  
            }
        }

        return prefix;
    }
};