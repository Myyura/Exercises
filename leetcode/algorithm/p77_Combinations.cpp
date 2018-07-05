/**
 * Combinations
 * Myyura
 */

/**
 * Given two integers n and k, return all possible combinations of k numbers out 
 * of 1 ... n.
 * 
 * Example:
 * Input: n = 4, k = 2
 * Output:
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

class Solution {
public:
    void combine(int n,
                 int k,
                 int start, 
                 std::vector<int>& result,
                 std::vector<std::vector<int>>& results) {
        if (result.size() == k) { 
            results.push_back(result);
            return;
        }
        
        for (int i = start; i < n; i++) {
            result.push_back(i + 1);
            combine(n, k, i + 1, result, results);
            result.pop_back();
        }
    }
    
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> results;
        std::vector<int> result;
        combine(n, k, 0, result, results);
        return results;
    }
};