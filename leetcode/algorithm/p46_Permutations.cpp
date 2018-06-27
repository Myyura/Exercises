/**
 * Permutations
 * Myyura
 */

/**
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */

class Solution {
public:
    // See problem 31 for details
    void reverse(std::vector<int>& nums, int k) {
        for (int i = k, j = nums.size() - 1; j > i; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    void nextPermutation(std::vector<int>& nums) {
        int k = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) { k = i; }
        }

        if (k == -1) {
            reverse(nums, 0);
            return;
        }

        int j = -1;
        for (int i = k + 1; i < nums.size(); i++) {
            if (nums[i] > nums[k]) { j = i; }
        }

        int temp = nums[k];
        nums[k] = nums[j];
        nums[j] = temp;
        reverse(nums, k + 1);
    }
    
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        unsigned long long total = 1;
        for (int i = 1; i <= nums.size(); i++) { total *= i; }
        for (int i = 0; i < total; i++) {
            result.push_back(nums);
            nextPermutation(nums);
        }
        return result;
    }
};