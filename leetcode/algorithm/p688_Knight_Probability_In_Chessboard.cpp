/**
 * Myyura
 */

/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 *
 * https://leetcode.com/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (46.98%)
 * Likes:    570
 * Dislikes: 127
 * Total Accepted:    32.4K
 * Total Submissions: 68.9K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * On an NxN chessboard, a knight starts at the r-th row and c-th column and
 * attempts to make exactly K moves. The rows and columns are 0 indexed, so the
 * top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
 * 
 * A chess knight has 8 possible moves it can make, as illustrated below. Each
 * move is two squares in a cardinal direction, then one square in an
 * orthogonal direction.
 * 
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and
 * moves there.
 * 
 * The knight continues moving until it has made exactly K moves or has moved
 * off the chessboard. Return the probability that the knight remains on the
 * board after it has stopped moving.
 * 
 * Example:
 * Input: 3, 2, 0, 0
 * Output: 0.0625
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
 * on the board.
 * From each of those positions, there are also two moves that will keep the
 * knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 * 
 * Note:
 * N will be between 1 and 25.
 * K will be between 0 and 100.
 * The knight always initially starts on the board.
 */

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if (N <= 0) { return 0.0; }
        if (K == 0) { return 1.0; }

        double prob[N][N][K + 1];
        for (int k = 0; k <= K; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    prob[i][j][k] = 0.0;
                }
            }
        }
        prob[r][c][0] = 1.0;
        for (int k = 1; k <= K; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (prob[i][j][k - 1] > 1e-6) {
                        if (i - 1 >= 0 && j - 2 >= 0) {
                            prob[i - 1][j - 2][k] += 0.125 * prob[i][j][k - 1];
                        }
                        if (i - 2 >= 0 && j - 1 >= 0) {
                            prob[i - 2][j - 1][k] += 0.125 * prob[i][j][k - 1];
                        }
                        if (i - 1 >= 0 && j + 2 < N) {
                            prob[i - 1][j + 2][k] += 0.125 * prob[i][j][k - 1];
                        }
                        if (i - 2 >= 0 && j + 1 < N) {
                            prob[i - 2][j + 1][k] += 0.125 * prob[i][j][k - 1];
                        }
                        if (i + 1 < N && j - 2 >= 0) {
                            prob[i + 1][j - 2][k] += 0.125 * prob[i][j][k - 1];
                        }
                        if (i + 2 < N && j - 1 >= 0) {
                            prob[i + 2][j - 1][k] += 0.125 * prob[i][j][k - 1];
                        }
                        if (i + 1 < N && j + 2 < N) {
                            prob[i + 1][j + 2][k] += 0.125 * prob[i][j][k - 1];
                        }
                        if (i + 2 < N && j + 1 < N) {
                            prob[i + 2][j + 1][k] += 0.125 * prob[i][j][k - 1];
                        }
                    }
                }
            }
        }

        double result = 0.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result += prob[i][j][K];
            }
        }

        return result;
    }
};
