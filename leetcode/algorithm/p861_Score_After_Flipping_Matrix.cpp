/**
 * Score After Flipping Matrix
 * Myyura
 */

/**
 * We have a two dimensional matrix A where each value is 0 or 1.
 * 
 * A move consists of choosing any row or column, and toggling each value in that
 *  row or column: changing all 0s to 1s, and all 1s to 0s.
 * 
 * After making any number of moves, every row of this matrix is interpreted as 
 * a binary number, and the score of the matrix is the sum of these numbers.
 * 
 * Return the highest possible score.
 * 
 * Example 1:
 * Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * Output: 39
 * Explanation:
 * Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 * 
 * Note:
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] is 0 or 1.
 */

class Solution {
public:
    /**
     * Basic idea:
     * 1 + 2 + 4 + ... + 2^(n-1) = 2^n - 1 < 2^n
     * 
     * So the more ones we get in the left, the resulting number will be greater.
     * First set all variables in first column to one by flipping rows, and then
     * set remaining variables to one by flipping column as many as possible.
     */
    int scoreOfMatrix(std::vector<std::vector<int>>& A) {
        int base, score = 0;
        for (int i = 0; i < A.size(); i++) {
            base = 1;
            for (int j = A[i].size() - 1; j >= 0; j--) {
                score += A[i][j] * base;
                base *= 2;
            }
        }
        
        return score;
    }
    
    void flipRow(std::vector<std::vector<int>>& A, int i) {
        for (int j = 0; j < A[i].size(); j++) { A[i][j] = !A[i][j]; }
    }
    
    void flipColumn(std::vector<std::vector<int>>& A, int j) {
        for (int i = 0; i < A.size(); i++) { A[i][j] = !A[i][j]; }
    }
    
    int matrixScore(std::vector<std::vector<int>>& A) {
        for (int i = 0; i < A.size(); i++) {
            if (A[i][0] != 1) { flipRow(A, i); }
        }
        
        for (int j = 1; j < A[0].size(); j++) {
            int onesBefore = 0;
            for (int i = 0; i < A.size(); i++) { onesBefore += A[i][j]; }
            flipColumn(A, j);
            int onesAfter = 0;
            for (int i = 0; i < A.size(); i++) { onesAfter += A[i][j]; }
            if (onesBefore > onesAfter) { flipColumn(A, j); }
        }
        
        return scoreOfMatrix(A);
    }
};