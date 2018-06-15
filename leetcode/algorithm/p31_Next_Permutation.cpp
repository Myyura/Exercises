/**
 * Next Permutation
 * Myyura
 */

/**
 * Implement next permutation, which rearranges numbers into the lexicographically 
 * next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible 
 * order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its corresponding 
 * outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

/**
 * https://en.wikipedia.org/wiki/Permutation#Algorithms_to_generate_permutations
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
};