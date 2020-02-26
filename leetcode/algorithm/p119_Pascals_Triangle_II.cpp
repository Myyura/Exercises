/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (46.69%)
 * Likes:    639
 * Dislikes: 188
 * Total Accepted:    251.5K
 * Total Submissions: 535.7K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * Follow up:
 * Could you optimize your algorithm to use only O(k) extra space?
 */

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) { return {1}; }

        std::vector<int> row1 = {1};
        std::vector<int> row2;
        bool is_row1 = false;
        for (int i = 1; i <= rowIndex; i++) {
            if (is_row1) {
                row1.clear();
                for (int j = 0; j <= i; j++) {
                    if (j == 0 || j == i) {
                        row1.push_back(1);
                    } else {
                        row1.push_back(row2[j] + row2[j - 1]);
                    }
                }
            } else {
                row2.clear();
                for (int j = 0; j <= i; j++) {
                    if (j == 0 || j == i) {
                        row2.push_back(1);
                    } else {
                        row2.push_back(row1[j] + row1[j - 1]);
                    }
                }
            }
            is_row1 = !is_row1;
        }

        if (is_row1) { return row2; }
        return row1;
    }
};

