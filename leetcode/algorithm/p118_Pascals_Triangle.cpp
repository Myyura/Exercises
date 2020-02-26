/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (49.76%)
 * Likes:    1074
 * Dislikes: 88
 * Total Accepted:    333.4K
 * Total Submissions: 666.1K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 */

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows == 0) { return {}; }

        std::vector<std::vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            std::vector<int> row;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    row.push_back(triangle[i - 1][j] + triangle[i - 1][j - 1]);
                }
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};
