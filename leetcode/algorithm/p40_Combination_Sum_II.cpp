/**
 * Combination Sum II
 * Myyura
 */

/**
 * Given a collection of candidate numbers (candidates) and a target number 
 * (target), find all unique combinations in candidates where the candidate 
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 * 
 * Example 2:
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 *   [1,2,2],
 *   [5]
 * ]
 */

class Solution {
public:
    // Brute-force
    void combinationSum2(std::vector<int>& candidates,
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
            /**
             * To aviod duplicates, only the first time we meet the candidate
             * candidates[i], we use it in our solution.
             */
            if (i == index || candidates[i] != candidates[i - 1]) {
                result.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], i + 1, result, results);
                result.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> results;
        std::vector<int> result;
        std::sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, target, 0, result, results);
        return results;
    }
};