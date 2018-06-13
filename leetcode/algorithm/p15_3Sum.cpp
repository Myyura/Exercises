/**
 * 3Sum
 * Myyura
 */

/**
 * Given an array nums of n integers, are there elements a, b, c in nums such 
 * that a + b + c = 0? Find all unique triplets in the array which gives the sum
 * of zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * Example:
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 */

class Solution {
public:
    /**
     * O(log(n) * n^2)
     * Sort array and use binary search to find the 3rd number
     */
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        
        int zeroBegin = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == 0) {
                zeroBegin = i;
                break;
            }
        }
        int zeroEnd = zeroBegin;
        for (; zeroEnd >= 0 && zeroEnd < nums.size() && nums.at(zeroEnd) == 0; zeroEnd++)
            ;

        int nZeros = zeroEnd - zeroBegin;
        if (nZeros >= 3) {
            result.push_back({0, 0, 0});
            nums.erase(nums.begin() + zeroBegin, nums.begin() + zeroEnd - 1);
        }

        int left, right;
        for (left = 0; left < nums.size() && nums.at(left) <= 0; left++) {
            for (right = nums.size() - 1; right > left && nums.at(right) >= 0; right--) {
                if (std::binary_search(nums.begin() + left + 1, nums.begin() + right, - nums.at(left) - nums.at(right))) {
                    result.push_back({nums.at(left), nums.at(right), 0 - nums.at(left) - nums.at(right)});
                }
                for (; right > left && nums.at(right - 1) == nums.at(right); right--)
                    ;
            }
            for (; left < right && nums.at(left + 1) == nums.at(left); left++)
                ;
        } 

        return result;
    }
};