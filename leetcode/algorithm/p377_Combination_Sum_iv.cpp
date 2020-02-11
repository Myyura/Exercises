/**
 * Myyura
 */

/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (44.34%)
 * Likes:    1095
 * Dislikes: 134
 * Total Accepted:    105.9K
 * Total Submissions: 238.6K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an integer array with all positive numbers and no duplicates, find the
 * number of possible combinations that add up to a positive integer target.
 * 
 * Example:
 * nums = [1, 2, 3]
 * target = 4
 * 
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * 
 * Note that different sequences are counted as different combinations.
 * 
 * Therefore the output is 7.
 * 
 * Follow up:
 * What if negative numbers are allowed in the given array?
 * How does it change the problem?
 * What limitation we need to add to the question to allow negative numbers?
 * 
 * Credits:
 * Special thanks to @pbrother for adding this problem and creating all test
 * cases.
 */

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        if (nums.size() == 0) { return 0; }
        // sum[i]: #possible combinations get target i
        std::vector<int> sum(target + 1, 0);
        sum[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    sum[i] += sum[i - nums[j]];
                }
            }
        }

        return sum[target];
    }
};
