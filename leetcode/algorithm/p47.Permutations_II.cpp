/**
 * Permutations II
 * Myyura
 */

/**
 * 
 * Given a collection of numbers that might contain duplicates, return all 
 * possible unique permutations.
 * 
 * Example:
 * Input: [1,1,2]
 * Output:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 */

class Solution {
public:
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
    
    std::vector<std::vector<int>> permuteUnique(vector<int>& nums) {
        std::set<std::vector<int>> resultUnique;
        unsigned long long total = 1;
        for (int i = 1; i <= nums.size(); i++) { total *= i; }
        for (int i = 0; i < total; i++) {
            resultUnique.insert(nums);
            nextPermutation(nums);
        }
        std::vector<std::vector<int>> result;
        for (auto& it : resultUnique) {
            result.push_back(it);
        }
        return result;
    }
};