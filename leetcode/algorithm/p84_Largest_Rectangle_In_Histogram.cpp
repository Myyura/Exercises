/**
 * Myyura
 */

/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (33.26%)
 * Likes:    2764
 * Dislikes: 66
 * Total Accepted:    219.7K
 * Total Submissions: 660.4K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * Example:
 * Input: [2,1,5,6,2,3]
 * Output: 10
 */

/* DP, O(n^2) time, O(n^2) space, case 94 time limit exceeded */
// class Solution {
// public:
//     int largestRectangleArea(std::vector<int>& heights) {
//         if (heights.size() == 0) { return 0; }

//         int n = heights.size();
//         std::vector<std::vector<int>> min_height;
//         for (int i = 0; i < n; i++) {
//             min_height.push_back(std::vector<int> (n - i));
//         }

//         /**
//          * min_height[i][j] = min(min_height[i][j - 1], height[j], 
//          *                        min_height[i + 1][j], height[i])
//          */
//         min_height[0][0] = heights[0];
//         int largest_rectangle_area = -1;
//         for (int j = 1; j < n; j++) {
//             min_height[0][j] = std::min(heights[j], min_height[0][j - 1]);
//         }

//         for (int i = 1; i < n; i++) {
//             min_height[i][0] = heights[i];
//         }

//         for (int i = n - 2; i > 0; i--) {
//             min_height[i][n - 1 - i] = std::min(heights[i], min_height[i + 1][n - 2 - i]);
//         }

//         for (int i = n - 2; i > 0; i--) {
//             for (int j = 1; j < n - 1 - i; j++) {
//                 min_height[i][j] = std::min(std::min(min_height[i][j - 1], heights[j + i]), std::min(min_height[i + 1][j - 1], heights[i]));
//             }
//         }
        
//         int largest_rectangle_area = -1;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n - i; j++) {
//                 int current_area = min_height[i][j] * (j + 1);
//                 largest_rectangle_area = std::max(largest_rectangle_area, current_area);
//             }
//         }

//         return largest_rectangle_area;
//     }
// };

/* O(n^2) time, O(1) space, case 95 time limit exceeded */
// class Solution {
// public:
//     int largestRectangleArea(std::vector<int>& heights) {
//         if (heights.size() == 0) { return 0; }

//         int n = heights.size(), largest_rectangle_area = -1;
//         for (int i = 0; i < n; i++) {
//             // case 90, max height = 2147483647
//             long min_height = 2147483648;
//             for (int j = i; j < n; j++) {
//                 min_height = std::min(min_height, (long)heights[j]);
//                 int current_area = min_height * (j - i + 1);
//                 largest_rectangle_area = std::max(current_area, largest_rectangle_area);
//             }
//         }

//         return largest_rectangle_area;
//     }
// };

/* Using stack, O(n) time, O(n) space, accepted */
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        if (heights.size() == 0) { return 0; }

        int n = heights.size(), largest_rectangle_area = -1;
        std::stack<int> height_index;
        int current;
        for (current = 0; current < n;) {
            if (height_index.empty() || heights[current] >= heights[height_index.top()]) {
                height_index.push(current++);
            } else {
                int last = height_index.top();
                height_index.pop();
                int new_area = heights[last] * (height_index.empty() ? current : (current - height_index.top() - 1));
                largest_rectangle_area = std::max(largest_rectangle_area, new_area);
            }
        }
       
        for (; !height_index.empty();) {
            int last = height_index.top();
            height_index.pop();
            int new_area = heights[last] * (height_index.empty() ? current : (current - height_index.top() - 1));
            largest_rectangle_area = std::max(largest_rectangle_area, new_area);
        }
        
        return largest_rectangle_area;
    }
};

