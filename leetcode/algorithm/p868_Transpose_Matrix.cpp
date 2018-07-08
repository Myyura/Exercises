/**
 * Transpose Matrix
 * Myyura
 */

/**
 * Given a matrix A, return the transpose of A.
 * 
 * The transpose of a matrix is the matrix flipped over it's main diagonal,  
 * switching the row and column indices of the matrix.
 * 
 * Example 1:
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 * 
 * Example 2:
 * Input: [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 *  
 * 
 * Note:
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 */

class Solution {
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A) {
        std::vector<std::vector<int>> AT;
        if (A.empty()) { return AT; }
        for (int j = 0; j < A[0].size(); j++) {
            std::vector<int> column;
            for (int i = 0; i < A.size(); i++) {
                column.push_back(A[i][j]);
            }
            AT.push_back(column);
        }
        
        return AT;
    }
};