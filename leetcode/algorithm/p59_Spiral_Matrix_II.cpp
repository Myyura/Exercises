/**
 * Spiral Matrix II
 * Myyura
 */

/**
 * Given a positive integer n, generate a square matrix filled with elements 
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * Input: 3
 * Output:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */

class Solution {
public:
        std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> result(n, std::vector<int> (n, 0));
        
        int numberInRow = n, numberInColumn = n;
        int r = 0, c = 0, dc = 1, dr = 1;
        for (int count = 0, j = 0; count < n * n; j++) {
            if (j % 2 == 0) {
                for (int k = 0; k < numberInRow; k++) { 
                    result[r][c] = ++count;
                    c += dr;
                }
                c -= dr, r += dc;
                numberInColumn--;
                dr = -dr;
            } else {
                for (int k = 0; k < numberInColumn; k++) {
                    result[r][c] = ++count;
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