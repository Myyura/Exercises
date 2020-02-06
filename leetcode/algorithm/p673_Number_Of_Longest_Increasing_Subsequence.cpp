/**
 * Myyura
 */

/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (34.79%)
 * Likes:    1058
 * Dislikes: 71
 * Total Accepted:    40.8K
 * Total Submissions: 117.2K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 * 
 * Example 1:
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 * 
 * Example 2:
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 * 
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
 */

/* DP, O(n^2) time, O(n) space, accepted */
class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        // LIS[i], first : length of LIS, second : #LIS, range [0...i] i.e. ends at nums[i]
        std::vector<std::pair<int, int>> LIS(nums.size());
        LIS[0].first = 1, LIS[0].second = 1;
        for (int i = 1; i < nums.size(); i++) {
            int length = 0, n = 0;
            // find the length of longest subseq if range [0...i-1]
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    if (length < LIS[j].first) {
                        length = LIS[j].first;
                        n = LIS[j].second;
                    } else if (length == LIS[j].first) {
                        // concatenate
                        n += LIS[j].second;
                    }
                }
            }
            // nums[i] is a samllest one
            if (length == 0) { n++; }
            LIS[i].first = length + 1;
            LIS[i].second = n;
        }

        int max_length = 0, total = 0;
        for (int i = 0; i < LIS.size(); i++) {
            if (max_length < LIS[i].first) { 
                max_length = LIS[i].first;
                total = LIS[i].second;
            } else if (max_length == LIS[i].first) {
                total += LIS[i].second;
            }
        }
        return total;
    }
};
