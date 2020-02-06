/**
 * Myyura
 */

/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 *
 * https://leetcode.com/problems/most-profit-assigning-work/description/
 *
 * algorithms
 * Medium (37.48%)
 * Likes:    285
 * Dislikes: 47
 * Total Accepted:    16K
 * Total Submissions: 42.6K
 * Testcase Example:  '[2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]'
 *
 * We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i]
 * is the profit of the ith job. 
 * 
 * Now we have some workers. worker[i] is the ability of the ith worker, which
 * means that this worker can only complete a job with difficulty at most
 * worker[i]. 
 * 
 * Every worker can be assigned at most one job, but one job can be completed
 * multiple times.
 * 
 * For example, if 3 people attempt the same job that pays $1, then the total
 * profit will be $3.  If a worker cannot complete any job, his profit is $0.
 * 
 * What is the most profit we can make?
 * 
 * Example 1:
 * Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker =
 * [4,5,6,7]
 * Output: 100 
 * Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get
 * profit of [20,20,30,30] seperately.
 * 
 * Notes:
 * 1 <= difficulty.length = profit.length <= 10000
 * 1 <= worker.length <= 10000
 * difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
 */

/* Greedy, O(n^2) time, time limit exceeded */
// class Solution {
// public:
//     int maxProfitAssignment(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
//         int result = 0;
//         for (int i = 0; i < worker.size(); i++) {
//             int max_profit = 0;
//             for (int j = 0; j < difficulty.size(); j++) {
//                 if (difficulty[j] <= worker[i] && max_profit < profit[j]) {
//                     max_profit = profit[j];
//                 }
//             }
//             result += max_profit;
//         }

//         return result;
//     }
// };

/* Sorting, O(nlogn + mlogm) time, accepted */
class Solution {
public:
    int maxProfitAssignment(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
        std::vector<std::pair<int, int>> difficulty_profit;
        for (int i = 0; i < difficulty.size(); i++) {
            difficulty_profit.push_back(std::make_pair(difficulty[i], profit[i]));
        }
        std::sort(difficulty_profit.begin(), difficulty_profit.end(),
                  [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> int {
                      return a.first < b.first;
                  });
        std::sort(worker.begin(), worker.end());
        
        int result = 0, current_best = 0;
        for (int i = 0, j = 0; i < worker.size(); i++) {
            for (; j < difficulty_profit.size() && worker[i] >= difficulty_profit[j].first; j++) {
                current_best = std::max(current_best, difficulty_profit[j].second);
            }
            result += current_best;
        }

        return result;
    }
};


