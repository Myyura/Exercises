/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (54.18%)
 * Likes:    1651
 * Dislikes: 1561
 * Total Accepted:    440.8K
 * Total Submissions: 811.2K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
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
    /* Greedy, O(n) time complexity, accepted */
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() == 0) { return 0; }

        int max_profit = 0;
        int max_price = prices[0], min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i - 1]) {
                max_profit += prices[i - 1] - min_price;
                max_price = min_price = prices[i];
            } else if (max_price < prices[i]) {
                max_price = prices[i];
            }
            
            if (i == prices.size() - 1) {
                max_profit += prices[i] - min_price > 0 ? prices[i] - min_price : 0;
            }
        }

        return max_profit;
    }
};

