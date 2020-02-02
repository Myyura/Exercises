/**
 * Myyura
 */

/*
 * @lc app=leetcode id=488 lang=cpp
 *
 * [488] Zuma Game
 *
 * https://leetcode.com/problems/zuma-game/description/
 *
 * algorithms
 * Hard (40.35%)
 * Likes:    173
 * Dislikes: 163
 * Total Accepted:    12.3K
 * Total Submissions: 30.6K
 * Testcase Example:  '"WRRBBW"\n"RB"'
 *
 * Think about Zuma Game. You have a row of balls on the table, colored red(R),
 * yellow(Y), blue(B), green(G), and white(W). You also have several balls in
 * your hand.
 * 
 * Each time, you may choose a ball in your hand, and insert it into the row
 * (including the leftmost place and rightmost place). Then, if there is a
 * group of 3 or more balls in the same color touching, remove these balls.
 * Keep doing this until no more balls can be removed.
 * 
 * Find the minimal balls you have to insert to remove all the balls on the
 * table. If you cannot remove all the balls, output -1.
 * 
 * 
 * Example 1:
 * Input: board = "WRRBBW", hand = "RB"
 * Output: -1
 * Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
 * 
 * 
 * Example 2:
 * Input: board = "WWRRBBWW", hand = "WRBRW"
 * Output: 2
 * Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW ->
 * empty
 * 
 * 
 * Example 3:
 * Input: board = "G", hand = "GGGGG"
 * Output: 2
 * Explanation: G -> G[G] -> GG[G] -> empty 
 * 
 * 
 * Example 4:
 * Input: board = "RBYYBBRRB", hand = "YRBGB"
 * Output: 3
 * Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] ->
 * BB[B] -> empty 
 * 
 * 
 * 
 * Constraints:
 * You may assume that the initial row of balls on the table won’t have any 3
 * or more consecutive balls with the same color.
 * The number of balls on the table won't exceed 16, and the string represents
 * these balls is called "board" in the input.
 * The number of balls in your hand won't exceed 5, and the string represents
 * these balls is called "hand" in the input.
 * Both input strings will be non-empty and only contain characters
 * 'R','Y','B','G','W'.
 */

class Solution {
public:
    std::pair<bool, int> dfs_helper(std::string& board, std::unordered_map<char, int>& hand) {
        if (board.size() == 0) { return std::make_pair(true, 0); }
        
        std::pair<bool, int> result = {false, 6};
        for (int current_group = 0, next_group = 0; current_group < board.size();) {
            for (; next_group < board.size() && board[next_group] == board[current_group]; next_group++) {}
            int group_length = next_group - current_group;
            int need_length;
            if (group_length >= 3) { need_length = 0; }
            if (group_length == 2) { need_length = 1; }
            if (group_length == 1) { need_length = 2; }

            if (hand[board[current_group]] >= need_length) {
                char deleted_color = board[current_group];
                hand[deleted_color] -= need_length;
                board.erase(current_group, group_length);
                std::pair<bool, int> temp = dfs_helper(board, hand);
                if (temp.first && temp.second + need_length < result.second) {
                    result.first = true;
                    result.second = temp.second + need_length;
                }
                board.insert(current_group, group_length, deleted_color);
                hand[deleted_color] += need_length;
            }

            current_group = next_group;
        }

        return result;
    }

    int findMinStep(std::string board, std::string hand) {
        std::unordered_map<char, int> hand_count;
        for (const auto& c : hand) { hand_count[c]++; }

        std::pair<bool, int> result = dfs_helper(board, hand_count);
        return result.first ? result.second : -1;
    }
};

