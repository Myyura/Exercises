/**
 * Jump Game II
 * Myyura
 */

/**
 * Given an array of non-negative integers, you are initially positioned at the 
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 
 * step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * You can assume that you can always reach the last index.
 */

class Solution {
public:
    // DP, TLE
    int jump(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 533346);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            int upper = std::min(i + nums[i], (int)(nums.size() - 1));
            for (int j = upper; j >= i; j--) {
                dp[j] = std::min(dp[i] + 1, dp[j]);
                if (j == nums.size() - 1) { return dp[j]; }
            }
        }
        
        return dp[nums.size() - 1];
    }

    int jump(std::vector<int>& nums) {
        int count = 0;
        for (int i = 0, canJump = 0, maxJump = 0; i < nums.size(); i++) {
            if (canJump < i) {
                canJump = maxJump;
                count++;
            }
            
            maxJump = std::max(maxJump, nums[i] + i);
        }
        
        return count;
    }    
};