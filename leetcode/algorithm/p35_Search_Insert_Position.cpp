/**
 * Search Insert Position 
 * Myyura
 */

/**
 * Given a sorted array and a target value, return the index if the target is 
 * found. If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * Example 2:
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * Example 3:
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * Example 4:
 * Input: [1,3,5,6], 0
 * Output: 0
 */

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if (target > nums.at(nums.size() - 1)) { return nums.size(); }
        if (target < nums.at(0)) { return 0; }

        int left = 0, right = nums.size() - 1;
        int index = (left + right) / 2;
        int number = nums.at(index);
        for (; left <= right; index = (left + right) / 2, number = nums.at(index)) {
            if (number > target) {
                right = index - 1;
            } else if (number < target) {
                left = index + 1;
            } else {
                return index;
            }
        }

        return index + 1;
    }
};