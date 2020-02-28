/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (35.81%)
 * Likes:    1653
 * Dislikes: 64
 * Total Accepted:    187.8K
 * Total Submissions: 521.6K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 * 
 * Example 2:
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * Example 3:
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 */

class Solution {
public:
    /* DP, O(n) time complexity, O(1) space complexity, accepted */
    int maxProfit(std::vector<int>& prices) {
        int min_price = 123456789;
        int max_profit = -123456789;
        int temp_profit = -123456789;
        int profit = -123456789;
        // first buy: p1, first sell: s1, second buy: p2, second sell: s2
        // profit = s1 - p1 + s2 - p2
        for (const auto& price : prices) {
            min_price = std::min(min_price, price);
            max_profit = std::max(max_profit, price - min_price);

            // temp_profit = s1 - p1 - p2
            temp_profit = std::max(temp_profit, max_profit - price);
            profit = std::max(profit, temp_profit + price);
        }

        return profit < 0 ? 0 : profit;
    }
};
