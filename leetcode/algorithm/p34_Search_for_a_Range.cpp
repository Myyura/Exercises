/**
 * Search for a Range
 * Myyura
 */

/**
 * Given an array of integers nums sorted in ascending order, find the starting 
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 */

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> result = {-1, -1};
        if (nums.empty()) { return result; }

        int mid = (nums.size() - 1) / 2;
        for (int i = 0, j = nums.size() - 1; i <= j; mid = (i + j) / 2) {
            if (nums[mid] >= target) {
                j = mid - 1;
            } else if (nums[mid] < target) {
                i = mid + 1;
            }

            if ((mid == 0 || nums[mid - 1] != target) && nums[mid] == target) {
                result[0] = mid;
            }
        }

        mid = (nums.size() - 1) / 2;
        for (int i = 0, j = nums.size() - 1; i <= j; mid = (i + j) / 2) {
            if (nums[mid] > target) {
                j = mid - 1;
            } else if (nums[mid] <= target) {
                i = mid + 1;
            }

            if ((mid == nums.size() - 1 || nums[mid + 1] != target) && nums[mid] == target) {
                result[1] = mid;
            }
        }

        return result;
    }
};