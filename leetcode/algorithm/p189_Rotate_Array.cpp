/**
 * Myyura
 */

/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (32.77%)
 * Likes:    2077
 * Dislikes: 730
 * Total Accepted:    400.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */

/**
 * O(n) time, O(1) space
 * the main idea is just move numbers one by one
 */
class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        if (k % nums.size() == 0) { return; }
        k = k % nums.size();

        int start = 0;
        for (int count = 0; count < nums.size();) {
            // count : how many numbers we have already moved
            int current = nums[start], next;
            for (int i = start + k; i % nums.size() != start && count < nums.size(); i += k) {
                next = nums[i % nums.size()];
                nums[i % nums.size()] = current;
                current = next;
                count++;
            }
            nums[start] = current;
            count++, start++;
        }
    }
};

