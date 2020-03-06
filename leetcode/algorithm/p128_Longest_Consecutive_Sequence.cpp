/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (43.65%)
 * Likes:    2651
 * Dislikes: 150
 * Total Accepted:    264.9K
 * Total Submissions: 603.6K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 */

class Solution {
public:
    /* sort the given array, O(nlogn) time complexity, O(n) space complexity, accepted */
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }

        sort(nums.begin(), nums.end());
        int max_length = 1, length = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) { continue; }
            if (nums[i] == nums[i - 1] + 1) {
                max_length = max(max_length, ++length);
            } else {
                length = 1;
            }
        }

        return max_length;
    }
};
