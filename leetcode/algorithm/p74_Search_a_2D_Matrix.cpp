/**
 * Search a 2D Matrix
 * Myyura
 */

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous 
 * row.
 * 
 * Example 1:
 * Input:
 * matrix = [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * Example 2:
 * Input:
 * matrix = [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 */

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) { return false; }
        int row = -1;
        for (int i = 0; i < matrix.size(); i++) {
            if (target >= matrix[i].front() && target <= matrix[i].back()) {
                row = i;
                break;
            }
        }
        
        if (row == -1) { return false; } 
        
        return std::binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};