/**
 * Spiral Matrix
 * Myyura
 */

/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of 
 * the matrix in spiral order.
 * 
 * Example 1:
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * Example 2:
 * Input:
 * [
 *   [1, 2, 3, 4],
 *   [5, 6, 7, 8],
 *   [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        if (matrix.empty()) { return result; }
        
        int numberInRow = matrix[0].size(), numberInColumn = matrix.size();
        int r = 0, c = 0, dc = 1, dr = 1;
        for (int count = 0, i = 0; count < matrix.size() * matrix[0].size(); i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < numberInRow; j++) { 
                    result.push_back(matrix[r][c]);
                    count++;
                    c += dr;
                }
                c -= dr, r += dc;
                numberInColumn--;
                dr = -dr;
            } else {
                for (int j = 0; j < numberInColumn; j++) {
                    result.push_back(matrix[r][c]);
                    count++;
                    r += dc;
                }
                r -= dc, c += dr;
                numberInRow--;
                dc = -dc;
            }
        }
        
        return result;
    }
};