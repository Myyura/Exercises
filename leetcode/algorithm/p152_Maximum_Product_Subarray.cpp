/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.90%)
 * Likes:    3315
 * Dislikes: 138
 * Total Accepted:    294K
 * Total Submissions: 950.1K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */

class Solution {
public:
    /* DP, O(n^2) time complexity, O(n) extra space complexity, accepted */
    int maxProduct_(vector<int>& nums) {
        // max_product[i]: maximum product subarray ends at i
        int max_product[nums.size()];
        max_product[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int max = -2147483648, product = 1;
            for (int j = i; j >= 0; j--) {
                product *= nums[j];
                if (product > max) {
                    max = product;
                }
            }

            max_product[i] = max;
        }

        int result = -2147483648;
        for (int i = 0; i < nums.size(); i++) {
            if (result < max_product[i]) {
                result = max_product[i];
            }
        }

        return result;
    }

    /* DP, O(n) time complexity, O(1) extra space complexity, accepted */
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0];

        // we need to focus on negative values, hence we need a variable min
        // to store the minimum product of the subarray ends at i
        int min = nums[0], max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int temp = min;
                min = max;
                max = temp;
            }
            max = std::max(max * nums[i], nums[i]);
            min = std::min(min * nums[i], nums[i]);

            max_product = std::max(max, max_product);
        }

        return max_product;
    }
};

