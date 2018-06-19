/**
 * Combination Sum
 * Myyura
 */

/**
 * Given a set of candidate numbers (candidates) (without duplicates) and a 
 * target number (target), find all unique combinations in candidates where the 
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of 
 * times.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 *   [7],
 *   [2,2,3]
 * ]
 * 
 * Example 2:
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 *   [2,2,2,2],
 *   [2,3,3],
 *   [3,5]
 * ]
 */

class Solution {
public:
    // Brute-force
    void combinationSum(std::vector<int>& candidates, 
                        int target,
                        int index,
                        std::vector<int>& result,
                        std::vector<std::vector<int>>& results) {
        if (target == 0) {
            results.push_back(result);
            return;
        }

        if (target < 0) { return; }

        for (int i = index; i < candidates.size(); i++) {
            result.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, result, results);
            result.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> results;
        std::vector<int> result;
        combinationSum(candidates, target, 0, result, results);
        return results;
    }
};