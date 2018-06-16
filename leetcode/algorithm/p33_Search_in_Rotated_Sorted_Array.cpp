/**
 * Search in Rotated Sorted Array
 * Myyura
 */

/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown 
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its index, 
 * otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 */

class Solution {
public:
    /**
     * Trivial idea, first find the pivot by somehow binary search, and then
     * using binary search find target in nums[0 ... pivot] and nums[pivot + 1, ...]
     */
    int binarySearchReturnIndex(std::vector<int>& v, int start, int len, int target) {
        auto it = std::lower_bound(v.begin() + start, v.begin() + start + len, target);
        if (it == v.end() || *it != target) {
            return -1;
        } else {
            return (int)std::distance(v.begin() + start, it);
        }   
    }

    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) { return -1; }

        int mid = (nums.size() - 1) / 2, pviot = -1;
        for (int i = 0, j = nums.size() - 1; i <= j; ) {
            if (i - 1 >= 0 && nums[i] < nums[i - 1]) {
                pviot = i - 1;
                break;
            } else if (i + 1 < nums.size() && nums[i] > nums[i + 1]) {
                pviot = i;
                break;
            } else if (j - 1 >= 0 && nums[j] < nums[j - 1]) {
                pviot = j - 1;
                break;
            } else if (j + 1 < nums.size() && nums[j] > nums[j + 1]) {
                pviot = j;
                break;
            }

            if (nums[0] < nums[(i + j) / 2]) {
                i = (i + j) / 2 + 1;
            } else if (nums[0] > nums[(i + j) / 2]) {
                j = (i + j) / 2 - 1;
            } else {
                break;
            }
        }

        int pos1 = binarySearchReturnIndex(nums, 0, pviot + 1, target);
        int pos2 = binarySearchReturnIndex(nums, pviot + 1, nums.size() - pviot - 1, target);
        if (pos1 != -1) { return pos1; }
        if (pos2 != -1) { return pos2 + pviot + 1; }
        return -1;
    }
};