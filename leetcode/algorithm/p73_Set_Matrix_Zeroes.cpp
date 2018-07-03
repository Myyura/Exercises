/**
 * Set Matrix Zeroes
 * Myyura
 */

/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
 * Do it in-place.
 * 
 * Example 1:
 * Input: 
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * Output: 
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 * 
 * Example 2:
 * Input: 
 * [
 *   [0,1,2,0],
 *   [3,4,5,2],
 *   [1,3,1,5]
 * ]
 * Output: 
 * [
 *   [0,0,0,0],
 *   [0,4,5,0],
 *   [0,3,1,0]
 * ]
 * 
 * Follow up:
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

class Solution {
public:
    /**
     * Basic idea: When we find a 0 in (i, j), set all number but 0 in column j 
     * to be -inf. We should not set column j to be zero since we need the zeros
     * to tell us if the row should be set to zero.
     * 
     * And after scanning the whole row i, if there is a 0 in row i, then set 
     * the whole row to zero.
     * 
     * Finally we substitute all -inf to 0.
     * 
     * Obviously O(mn) time O(1) space.
     */
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            bool hasZero = false;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    hasZero = true;
                    for (int k = 0; k < matrix.size(); k++) {
                        matrix[k][j] = matrix[k][j] == 0 ? 0 : -1314520;
                    }
                }
            }
            
            if(hasZero) { for(int j = 0; j < matrix[0].size(); j++) { matrix[i][j] = 0; } }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == -1314520) { matrix[i][j] = 0; }
            }
        }
    }
};