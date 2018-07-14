/**
 * Subsets II
 * Myyura
 */

/**
 * Given a collection of integers that might contain duplicates, nums, return 
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * Input: [1,2,2]
 * Output:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        
        result.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            std::vector<std::vector<int>> tempResult;
            for (auto& it : result) {
                if (it.empty() || it[it.size() - 1] != nums[i]) { tempResult.push_back(it); }
                it.push_back(nums[i]);
                tempResult.push_back(it);
            }
            result = tempResult;
        }
        
        return result;
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<int> binary(nums.size(), 0);
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> uniqueResult;
        for (; nums.size() > 0;) {
            std::vector<int> subset;
            bool isEnd = true;
            for (int i = 0; i < nums.size(); i++) {
                if (binary[i] != 0) { subset.push_back(nums[i]); }
                else { isEnd = false; }
            }
            uniqueResult.insert(subset);
            if (isEnd) { break; }
            
            int carry = 0;
            binary[0]++;
            for (int i = 0; i < binary.size(); i++) {
                binary[i] += carry;
                carry = binary[i] / 2;
                binary[i] = binary[i] % 2;
            }
        }
        
        std::vector<std::vector<int>> result;
        for (auto& it : uniqueResult) { result.push_back(it); }
        return result;
    }
};