/**
 * Sudoku Solver
 * Myyura
 */

/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 
 * sub-boxes of the grid.
 * Empty cells are indicated by the character '.'.
 * 
 * Note:
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique 
 * solution.
 * The given board size is always 9x9.
 */

class Solution {
public:
    /**
     * A simple brute-force algorithm
     * square number :
     * 0 1 2
     * 3 4 5
     * 6 7 8
     * 
     * square[i][j] == 1 means that number j has already in square i
     * row[i][j] == 1 means that number j has already in row i
     * col[i][j] == 1 means that number j has already in column i
     */
    bool solveSudoku(std::vector<std::vector<char>>& board,
                    std::vector<std::vector<int>>& square,
                    std::vector<std::vector<int>>& row,
                    std::vector<std::vector<int>>& col,
                    int& count) {
        if (count == 81) { return true; }

        int i, j;
        for (i = 0; i < 9; i++) {
            int flag = 1;
            for (j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    flag = 0;
                    break; 
                }
            }
            if (!flag) { break; }
        }

        int squareIndex = (i / 3) * 3 + j / 3;
        for (int k = 1; k <= 9; k++) {
            if (row[i][k] == 1 || col[j][k] == 1 || square[squareIndex][k] == 1) {
                continue;
            }

            board[i][j] = k + '0';
            row[i][k]++, col[j][k]++, square[squareIndex][k]++, count++;
            if (solveSudoku(board, square, row, col, count)) { return true; }
            board[i][j] = '.';
            row[i][k]--, col[j][k]--, square[squareIndex][k]--, count--;
        }

        return false;
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<int>> square(9), row(9), col(9);
        for (int i = 0; i < 9; i++) {
            square[i] = (std::vector<int> (10, 0));
            row[i] = (std::vector<int> (10, 0));
            col[i] = (std::vector<int> (10, 0));
        }

        int count = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int squareIndex = (i / 3) * 3 + j / 3;
                if (board[i][j] != '.') {
                    count++;
                    int pos = (int)(board[i][j] - '0');
                    row[i][pos]++;
                    col[j][pos]++;
                    square[squareIndex][pos]++;
                }
            }
        }
        
        solveSudoku(board, square, row, col, count);
    }
};