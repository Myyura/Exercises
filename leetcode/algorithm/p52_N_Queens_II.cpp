/**
 * N-Queens II
 * Myyura
 */

/**
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
 * such that no two queens attack each other.
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens' 
 * placement, where 'Q' and '.' both indicate a queen and an empty space 
 * respectively.
 * 
 * Example:
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as shown 
 * below.
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 * 
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 */

class Solution {
public:
    bool isValidPosition(std::vector<std::string>& result, int row, int col) {
        for (int i = row, j = 0; j < result.size(); j++) {
            if (result[i][j] == 'Q') { return false; }
        }

        for (int i = 0, j = col; i < result.size(); i++) {
            if (result[i][j] == 'Q') { return false; }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (result[i][j] == 'Q') { return false; }
        }

        for (int i = row + 1, j = col + 1; i < result.size() && j < result.size(); i++, j++) {
            if (result[i][j] == 'Q') { return false; }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < result.size(); i--, j++) {
            if (result[i][j] == 'Q') { return false; }
        }

        for (int i = row + 1, j = col - 1; i < result.size() && j >= 0; i++, j--) {
            if (result[i][j] == 'Q') { return false; }
        }
        return true;
    }

    void solveNQueens(int n, int k, std::vector<std::string>& result, int& total) {
        if (k == n) { 
            total++;
            return;
        }
        for (int i = k, j = 0; j < result.size(); j++) {
            if (isValidPosition(result, i, j)) {
                result[i][j] = 'Q';
                solveNQueens(n, k + 1, result, total);
                result[i][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int total = 0;
        std::vector<std::string> result(n, std::string(n, '.'));
        solveNQueens(n, 0, result, total);
        return total; 
    }
};