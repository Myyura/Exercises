/**
 * Search in Rotated Sorted Array II
 * Myyura
 */

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown 
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true, 
 * otherwise return false.
 * 
 * Example 1:
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * Example 2:
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * This is a follow up problem to Search in Rotated Sorted Array, where nums may 
 * contain duplicates.
 * Would this affect the run-time complexity? How and why?
 */

class Solution {
public:
    // O(n) the worst case
    int findQviot(std::vector<int>& nums, int i, int j) {
        if (i > j) { return -1; }
        if (i - 1 >= 0 && nums[i] < nums[i - 1]) { return i - 1; }
        if (i + 1 < nums.size() && nums[i] > nums[i + 1]) { return i; }
        if (j - 1 >= 0 && nums[j] < nums[j - 1]) { return j - 1; }
        if (j + 1 < nums.size() && nums[j] > nums[j + 1]) { return j; }
        
        if (nums[0] < nums[(i + j) / 2]) { return findQviot(nums, (i + j) / 2 + 1, j); }
        if (nums[0] > nums[(i + j) / 2]) { return findQviot(nums, i, (i + j) / 2 - 1); }
        int q1 = findQviot(nums, (i + j) / 2 + 1, j);
        int q2 = findQviot(nums, i, (i + j) / 2 - 1);
        return q1 == -1 ? q2 : q1;
    }
    
    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) { return false; }
        int qviot = findQviot(nums, 0, nums.size() - 1);
        return (std::binary_search(nums.begin(), nums.begin() + qviot + 1, target)
                || std::binary_search(nums.begin() + qviot + 1, nums.end(), target));
    }
};