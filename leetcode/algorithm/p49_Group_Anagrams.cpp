/**
 * Group Anagrams
 * Myyura
 */

/**
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 *   ["ate","eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * 
 * Note:
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 */

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> result;
        for (auto& it : strs) {
            std::string standard = it;
            std::sort(standard.begin(), standard.end());
            int index = -1;
            for (int i = 0; i < result.size(); i++) {
                if (result[i].back() == standard) {
                    result[i].pop_back();
                    result[i].push_back(it);
                    result[i].push_back(standard);
                    index = i;
                }
            }

            if (index == -1) {
                std::vector<std::string> temp;
                temp.push_back(it);
                temp.push_back(standard);
                result.push_back(temp);
            }
        }

        for (auto& it : result) { it.pop_back(); }
        return result;
    }
};
