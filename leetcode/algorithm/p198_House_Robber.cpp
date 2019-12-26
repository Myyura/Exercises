/**
 * House Robber
 * Myyura
 */

/**
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed, the only constraint 
 * stopping you from robbing each of them is that adjacent houses have security 
 * system connected and it will automatically contact the police if two adjacent 
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of 
 * each house, determine the maximum amount of money you can rob tonight without 
 * alerting the police.
 * 
 * Example 1:
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 *              Total amount you can rob = 2 + 9 + 1 = 12.
 */

/* First version */
class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        if (nums.size() == 1) { return nums[0]; }
        
        int maxMoney = 0;
        
        std::vector<int> money;
        money.push_back(nums[0]), money.push_back(nums[0]);
        for (int i = 2; i < nums.size(); i++) {
            money.push_back(std::max(money[i - 1], money[i - 2] + nums[i]));
        }
        maxMoney = money[nums.size() - 1];
        
        money[0] = 0, money[1] = nums[1];
        for (int i = 2; i < money.size(); i++) {
            money[i] = std::max(money[i - 1], money[i - 2] + nums[i]);
        }
        maxMoney = std::max(maxMoney, money[nums.size() - 1]);
        
        return maxMoney;
    }
};

/* Refined version */
class Solution {
public:
    int rob(std::vector<int>& nums) {
       int money1 = 0, money2 = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i & 1) { money2 = std::max(money2 + nums[i], money1); }
            else { money1 = std::max(money1 + nums[i], money2); }
        }
        
        return std::max(money1, money2);
    }
};