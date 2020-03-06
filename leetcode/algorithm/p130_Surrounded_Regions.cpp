/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (25.14%)
 * Likes:    1192
 * Dislikes: 543
 * Total Accepted:    187.5K
 * Total Submissions: 736.8K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * After running your function, the board should be:
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * Explanation:
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 */

class Solution {
public:
    /* DFS is used for finding a surrounded region, accepted */
    int dfs_helper(
        vector<vector<char>>& board,
        int i, int j,
        vector<vector<bool>>& visited,
        vector<pair<int, int>>& current_area) {
        
        visited[i][j] = true;
        bool surrounded = true;
        if (board[i][j] == 'O') {
            current_area.push_back({i, j});
            if (i - 1 >= 0 && !visited[i - 1][j]) {
                surrounded &= dfs_helper(board, i - 1, j, visited, current_area);
            }
            if (j - 1 >= 0 && !visited[i][j - 1]) {
                surrounded &= dfs_helper(board, i, j - 1, visited, current_area);
            }
            if (i + 1 < board.size() && !visited[i + 1][j]) {
                surrounded &= dfs_helper(board, i + 1, j, visited, current_area);
            }
            if (j + 1 < board[0].size() && !visited[i][j + 1]) {
                surrounded &= dfs_helper(board, i, j + 1, visited, current_area);
            }
            if (i - 1 < 0 || j - 1 < 0 || i + 1 >= board.size() || j + 1 >= board[0].size()) {
                surrounded = false;
            }
        }

        return surrounded;
    }

    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) { return; }

        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        vector<pair<int, int>> area;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O') {
                    bool surrounded = dfs_helper(board, i, j, visited, area);
                    for (const auto& xy : area) {
                        if (surrounded) {
                            board[xy.first][xy.second] = 'X';
                        } else {
                            board[xy.first][xy.second] = '.';
                        }
                    }

                    area.clear();
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
