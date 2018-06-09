/**
 * 3Sum Closest
 * Myyura
 */

/**
 * Given an array nums of n integers and an integer target, find three integers 
 * in nums such that the sum is closest to target. Return the sum of the three 
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

class Solution {
public:
    int myAbs(int n) {
        return n >= 0 ? n : -n;
    }
    
    int threeSumClosest(std::vector<int>& nums, int target) {
        int result;
        int diff = std::numeric_limits<int>::max();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int curTarget = target - nums.at(i);
            for (int left = i + 1, right = nums.size() - 1; left < right;) {
                int curSum = nums.at(left) + nums.at(right);
                if (diff > myAbs(curTarget - curSum)) {
                    result = nums.at(i) + nums.at(left) + nums.at(right);
                    diff = myAbs(curTarget - curSum);
                }

                if (curSum < curTarget) {
                    left++;
                }
                
                if (curSum > curTarget) {
                    right--;
                }

                if (curSum == curTarget) {
                    return result;
                }
            }
        }

        return result;
    }
};