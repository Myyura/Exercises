/**
 * Valid Sudoku
 * Myyura
 */

/**
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be 
 * validated according to the following rules:
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without 
 * repetition.
 * 
 * A partially filled sudoku which is valid.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled with 
 * the character '.'.
 * 
 * Example 1:
 * Input:
 * [
 *   ["5","3",".",".","7",".",".",".","."],
 *   ["6",".",".","1","9","5",".",".","."],
 *   [".","9","8",".",".",".",".","6","."],
 *   ["8",".",".",".","6",".",".",".","3"],
 *   ["4",".",".","8",".","3",".",".","1"],
 *   ["7",".",".",".","2",".",".",".","6"],
 *   [".","6",".",".",".",".","2","8","."],
 *   [".",".",".","4","1","9",".",".","5"],
 *   [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * Example 2:
 * Input:
 * [
 *   ["8","3",".",".","7",".",".",".","."],
 *   ["6",".",".","1","9","5",".",".","."],
 *   [".","9","8",".",".",".",".","6","."],
 *   ["8",".",".",".","6",".",".",".","3"],
 *   ["4",".",".","8",".","3",".",".","1"],
 *   ["7",".",".",".","2",".",".",".","6"],
 *   [".","6",".",".",".",".","2","8","."],
 *   [".",".",".","4","1","9",".",".","5"],
 *   [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner being 
 * modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is 
 * invalid.
 * 
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily 
 * solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 */

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board, int square) {
        int start = (square - 1) / 3 * 27 + ((square - 1) % 3) * 3;
        int end = start + 20;
        std::vector<int> isExist(10, 0);
        for (int i = 0; i + start <= end;) {
            if (board[(i + start) / 9][(i + start) % 9] != '.') {
                int pos = (int)(board[(i + start) / 9][(i + start) % 9] - '0');
                if (++isExist[pos] > 1) { return false; }
            }

            if (++i == 3) { 
                i = 0;
                start += 9;
            }
        }

        return true;
    }

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<int> isExist(10, 0);
        // Check rows
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int pos = (int)(board[i][j] - '0');
                    if (++isExist[pos] > 1) { return false; }
                }
            }
            std::fill(isExist.begin(), isExist.end(), 0);
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    int pos = (int)(board[i][j] - '0');
                    if (++isExist[pos] > 1) { return false; }
                }
            }
            std::fill(isExist.begin(), isExist.end(), 0);
        }

        bool isSquareValid = true;
        for (int i = 1; i <= 9; i++) {
            isSquareValid = isSquareValid && isValidSudoku(board, i);
            if (!isSquareValid) { return false; }
        }
        return isSquareValid;
    }
};