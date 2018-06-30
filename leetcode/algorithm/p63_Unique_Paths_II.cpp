/**
 * Unique Paths II
 * Myyura
 */

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in 
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is 
 * trying to reach the bottom-right corner of the grid (marked 'Finish' in the 
 * diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths 
 * would there be?
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * Input:
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 */

/**
 * Search Lattice path or see my solution to project euler 15 for details
 */
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) { return 0; }
        int dp[obstacleGrid.size()][obstacleGrid[0].size()];
        dp[0][0] = 1;
        for (int i = 1; i < obstacleGrid[0].size(); i++) {
            dp[0][i] = dp[0][i - 1] == 0 || obstacleGrid[0][i] == 1 ? 0 : 1;
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            dp[i][0] = dp[i - 1][0] == 0 || obstacleGrid[i][0] == 1 ? 0 : 1;    
        }
        
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};