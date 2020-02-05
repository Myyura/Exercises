/**
 * Myyura
 */

/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (31.77%)
 * Likes:    1754
 * Dislikes: 89
 * Total Accepted:    159.7K
 * Total Submissions: 502.3K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 * 
 * Example:
 * Input: 
 * board = [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 * words = ["oath","pea","eat","rain"]
 * Output: ["eat","oath"]
 *
 * Note:

 * All inputs are consist of lowercase letters a-z.
 * The values of words are distinct.
 */

/* Trie + DFS on board, inefficient but accepted */
class Solution {
public:
    struct TrieNode {
        struct TrieNode *children[26];
        bool is_end;

        TrieNode(void) {
            for (int i = 0; i < 26; i++) {
                this->children[i] = nullptr;
            }
            this->is_end = false;
        }
    };

    void insert(struct TrieNode *root, const std::string& key) {
        struct TrieNode *current = root;

        for (int i = 0; i < key.length(); i++) {
            if (!(current->children[key[i] - 'a'])) {
                current->children[key[i] - 'a'] = new TrieNode();
            }

            current = current->children[key[i] - 'a'];
        }

        current->is_end = true;
    }

    int search(struct TrieNode *root, const std::string& key) {
        struct TrieNode *current = root;

        for (int i = 0; i < key.length(); i++) {
            if (!(current->children[key[i] - 'a'])) {
                return 0;
            }

            current = current->children[key[i] - 'a'];
        }

        if (current == nullptr) { 
            return 0; 
        }
        return current->is_end ? 2 : 1;
    }

    void dfs_helper(
        std::vector<std::vector<char>>& board,
        int i, int j,
        std::vector<std::vector<bool>>& visited,
        std::string& current_word,
        TrieNode* word_trie,
        std::unordered_set<std::string>& existed_words,
        
        int max_length) {
        
        current_word.push_back(board[i][j]);
        if (current_word.size() > max_length) { 
            current_word.pop_back();
            return; 
        }

        int search_result = search(word_trie, current_word);
        if (search_result == 0) {
            current_word.pop_back();
            return; 
        } else if (search_result == 2) {
            existed_words.insert(current_word);
        }

        if (i - 1 >= 0 && !visited[i - 1][j]) {
            visited[i - 1][j] = true;
            dfs_helper(board, i - 1, j, visited, current_word, word_trie, existed_words, max_length);
            visited[i - 1][j] = false;
        }

        if (i + 1 < board.size() && !visited[i + 1][j]) {
            visited[i + 1][j] = true;
            dfs_helper(board, i + 1, j, visited, current_word, word_trie, existed_words, max_length);
            visited[i + 1][j] = false;
        }

        if (j - 1 >= 0 && !visited[i][j - 1]) {
            visited[i][j - 1] = true;
            dfs_helper(board, i, j - 1, visited, current_word, word_trie, existed_words, max_length);
            visited[i][j - 1] = false;
        }

        if (j + 1 < board[0].size() && !visited[i][j + 1]) {
            visited[i][j + 1] = true;
            dfs_helper(board, i, j + 1, visited, current_word, word_trie, existed_words, max_length);
            visited[i][j + 1] = false;
        }
        
        current_word.pop_back();
    }

    void dfs_board(
        std::vector<std::vector<char>>& board,
        TrieNode* word_trie,
        std::unordered_set<std::string>& existed_words,
        
        // for cutting
        int max_length) {
        
        int m = board.size(), n;
        if (m > 0) { 
            n = board[0].size(); 
        } else { 
            return;
        }

        std::vector<std::vector<bool>> visited(m, std::vector<bool> (n, false));
        std::string current_word = "";
        for (int s = 0; s < 26; s++) {
            if (word_trie->children[s] == nullptr) { continue; }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] != s + 'a') { continue; }
                    visited[i][j] = true;
                    dfs_helper(board, i, j, visited, current_word, word_trie, existed_words, max_length);
                    visited[i][j] = false;
                }
            }
        }
    }

    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        TrieNode *word_trie = new TrieNode();
        int max_length = 0;
        for (const auto& w : words) {
            max_length = w.size() > max_length ? w.size() : max_length;
            insert(word_trie, w);
        }

        std::unordered_set<std::string> existed_words;
        dfs_board(board, word_trie, existed_words, max_length);
        std::vector<std::string> result;
        for (const auto& w : existed_words) {
            result.push_back(w);
        }
        return result;
    }
};
