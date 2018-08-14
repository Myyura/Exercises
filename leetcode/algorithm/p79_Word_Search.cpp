/**
 * Word Search
 * Myyura
 */

/**
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell, where 
 * "adjacent" cells are those horizontally or vertically neighboring. The same 
 * letter cell may not be used more than once.
 * 
 * Example:
 * board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 */

class Solution {
public:
    bool helper(std::vector<std::vector<char>>& board,
                std::vector<std::vector<bool>>& isVisited,
                int i, int j, int k,
                std::string& word) {
        if (k == word.size()) { return true; }
        
        if (i < 0 || i >= board.size()) { return false; }
        if (j < 0 || j >= board[0].size()) { return false; }
        
        if (isVisited[i][j]) { return false; }
        isVisited[i][j] = true;
        if (board[i][j] != word[k]) {
            isVisited[i][j] = false;
            return false;
        }
        
        bool isExisted = false;
        isExisted = isExisted || helper(board, isVisited, i + 1, j, k + 1, word);
        isExisted = isExisted || helper(board, isVisited, i, j + 1, k + 1, word);
        isExisted = isExisted || helper(board, isVisited, i - 1, j, k + 1, word);
        isExisted = isExisted || helper(board, isVisited, i, j - 1, k + 1, word);
        isVisited[i][j] = false;
        return isExisted;
    }
    
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if (board.empty()) { return false; }
        
        std::vector<std::vector<bool>> isVisited(board.size(), std::vector<bool> (board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(helper(board, isVisited, i, j, 0, word)) { return true; }
            }
        }
        
        return false;
    }
};