/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (27.28%)
 * Likes:    2405
 * Dislikes: 985
 * Total Accepted:    358K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * Example 1:
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * Example 2:
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 */

class Solution {
public:
    /* DFS search, test case 21, time limit exceeded */
    // int difference(std::string& w1, std::string& w2) {
    //     int diff = 0;
    //     for (int i = 0; i < w1.size(); i++) {
    //         diff += !(w1[i] == w2[i]);
    //     }
    //     return diff;
    // }

    // void dfs_search(
    //     std::string& current_word,
    //     std::string& end_word,
    //     std::vector<string>& word_list,
    //     std::vector<bool>& used,
    //     int length,
    //     int& min_length) {
        
    //     if (length >= min_length) { return; }

    //     int diff = difference(current_word, end_word);
    //     if (diff == 0) {
    //         min_length = std::min(length, min_length);
    //         return;
    //     }

    //     for (int i = 0; i < word_list.size(); i++) {
    //         if (used[i]) { continue; }
    //         if (difference(current_word, word_list[i]) == 1) {
    //             int diff_i = difference(word_list[i], end_word);
    //             if (diff_i <= diff && diff_i + length <= min_length) {
    //                 used[i] = true;
    //                 dfs_search(word_list[i], end_word, word_list, used, length + 1, min_length);
    //                 used[i] = false;
    //             }
    //         }
    //     }
    // }

    // int ladderLength(std::string beginWord, std::string endWord, std::vector<string>& wordList) {
    //     int min_length = wordList.size() + 1;
    //     std::vector<bool> used(wordList.size(), false);
    //     dfs_search(beginWord, endWord, wordList, used, 1, min_length);
    //     return min_length == wordList.size() + 1 ? 0 : min_length;
    // }

    /* Approach 1 in solution */
    int ladderLength(std::string beginWord, std::string endWord, std::vector<string>& wordList) {
        int word_length = beginWord.size();

        std::unordered_map<std::string, std::vector<std::string>> all_combo;
        for (int i = 0; i < wordList.size(); i++) {
            std::vector<std::string> combo(word_length);
            for (int j = 0; j < word_length; j++) {
                std::string intermediate = wordList[i].substr(0, j) + "*" + wordList[i].substr(j + 1, word_length - j + 1);
                all_combo[intermediate].push_back(wordList[i]);
            }
        }

        // Queue for BFS
        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});

        std::unordered_map<std::string, bool> visited;
        visited[beginWord] = true;

        for (; !q.empty();) {
            std::pair<std::string, int> current = q.front();
            q.pop();
            
            std::string word = current.first;
            int level = current.second;
            for (int i = 0; i < word_length; i++) {
                std::string intermediate = word.substr(0, i) + "*" + word.substr(i + 1, word_length - i + 1);
                for (const auto& adjacent_word : all_combo[intermediate]) {
                    if (adjacent_word == endWord) {
                        return level + 1;
                    }

                    if (visited.count(adjacent_word) == 0) {
                        visited[adjacent_word] = true;
                        q.push({adjacent_word, level + 1});
                    }
                }
            }
        }

        return 0;
    }
};
