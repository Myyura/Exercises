/**
 * Minimum Path Sum
 * Myyura
 */

/**
 * Given a m x n grid filled with non-negative numbers, find a path from top 
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * Input:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int dp[grid.size()][grid[0].size()];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        
        for (int i = 1; i < grid[0].size(); i++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                dp[i][j] = std::min(grid[i][j] + dp[i - 1][j], grid[i][j] + dp[i][j - 1]);
            }
        }
        
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};