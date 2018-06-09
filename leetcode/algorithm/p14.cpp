/**
 * Longest Common Prefix         
 * Myyura
 */

/**
 * Write a function to find the longest common prefix string amongst an array of 
 * strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * Example 2:
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * Note: All given inputs are in lowercase letters a-z.
 */

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        std::string prefix = strs.at(0);
        for (int i = 0; ; i++) {
            for (auto &it : strs) {
                if (i == it.size() || prefix.at(i) != it.at(i)) {
                    return prefix.substr(0, i);
                }  
            }
        }

        return prefix;
    }
};