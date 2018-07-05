/**
 * Subsets
 * Myyura
 */

/**
 * Given a set of distinct integers, nums, return all possible subsets (the 
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */

class Solution {
public:
    /**
     * Note that the size of power set of a size n set is 2^n.
     * Hence we can enumerate all the subsets in terms of the binary of n bits
     * 
     * Example:
     * input array [1, 2, 3], n = 3
     * 000 -> []
     * 001 -> [3]
     * 010 -> [2]
     * 011 -> [2, 3]
     * ...
     * 111 -> [1, 2, 3]
     */
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<int> binary(nums.size(), 0);
        std::vector<std::vector<int>> result;
        for (; nums.size() > 0;) {
            std::vector<int> subset;
            bool isEnd = true;
            for (int i = 0; i < nums.size(); i++) {
                if (binary[i] != 0) { subset.push_back(nums[i]); }
                else { isEnd = false; }
            }
            result.push_back(subset);
            if (isEnd) { break; }
            
            int carry = 0;
            binary[0]++;
            for (int i = 0; i < binary.size(); i++) {
                binary[i] += carry;
                carry = binary[i] / 2;
                binary[i] = binary[i] % 2;
            }
        }
        
        return result;
    }
};