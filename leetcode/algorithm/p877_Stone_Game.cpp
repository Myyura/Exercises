/**
 * Stone Game
 * Myyura
 */

/**
 * Alex and Lee play a game with piles of stones.  There are an even number of 
 * piles arranged in a row, and each pile has a positive integer number of 
 * stones piles[i].
 * 
 * The objective of the game is to end with the most stones.  The total number of 
 * stones is odd, so there are no ties.
 * 
 * Alex and Lee take turns, with Alex starting first.  Each turn, a player takes 
 * the entire pile of stones from either the beginning or the end of the row.  
 * This continues until there are no more piles left, at which point the person 
 * with the most stones wins.
 * 
 * Assuming Alex and Lee play optimally, return True if and only if Alex wins the 
 * game.
 * 
 * Example 1:
 * Input: [5,3,4,5]
 * Output: true
 * Explanation: 
 * Alex starts first, and can only take the first 5 or the last 5.
 * Say he takes the first 5, so that the row becomes [3, 4, 5].
 * If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 
 * points.
 * If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win 
 * with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alex, so we 
 * return true.
 * 
 * Note:
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles) is odd.
 */

class Solution {
public:
    /** 
     * Alex plays optimally, so he will maximize his #stones and minimize the 
     * #stones of Lee
     */
    int alexMax(std::vector<int>& piles, std::pair<int, int>& range,
                 std::map<std::pair<int, int>, int>& maxCache,
                 std::map<std::pair<int, int>, int>& minCache) {
        if (maxCache.count(range) == 1) { return maxCache[range]; }
        int i = range.first, j = range.second;
        if (i == j) { return 0; }
        std::pair<int, int> left = std::make_pair(i + 1, j);
        std::pair<int, int> right = std::make_pair(i, j - 1);
        maxCache[range] = std::max(piles[i] + leeMin(piles, left, maxCache, minCache),
                                   piles[j] + leeMin(piles, right, maxCache, minCache));
        return maxCache[range];
    }
    
    int leeMin(std::vector<int>& piles, std::pair<int, int>& range,
                std::map<std::pair<int, int>, int>& maxCache,
                std::map<std::pair<int, int>, int>& minCache) {
        if (minCache.count(range) == 1) { return minCache[range]; }
        int i = range.first, j = range.second;
        if (i == j) { return piles[i]; }
        std::pair<int, int> left = std::make_pair(i + 1, j);
        std::pair<int, int> right = std::make_pair(i, j - 1);
        minCache[range] = std::min(alexMax(piles, left, maxCache, minCache),
                                   alexMax(piles, right, maxCache, minCache));
        return minCache[range];
    }
    
    bool stoneGame(std::vector<int>& piles) {
        std::map<std::pair<int, int>, int> maxCache, minCache;
        std::pair<int, int> start = std::make_pair(0, piles.size() - 1);
        int alexStones = alexMax(piles, start, maxCache, minCache);
        int total = 0;
        for (auto p : piles) { total += p; }
        return alexStones > total / 2;
    }

    /**
     * Also an DP approach,
     * dp[i][j] means the biggest number of stones you can get more than 
     * opponent picking piles in piles[i] ~ piles[j].
     * 
     * You can first pick piles[i] or piles[j].
     * If you pick piles[i], your result will be piles[i] - dp[i + 1][j]
     * If you pick piles[j], your result will be piles[j] - dp[i][j - 1]
     * 
     * So we get:
     * dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
     */
    bool stoneGame(std::vector<int>& piles) {
        std::vector<std::vector<int>> dp(piles.size(), std::vector<int>(piles.size(), 0));
        for (int i = 0; i < piles.size(); i++) { dp[i][i] = piles[i]; }
        for (int j = 1; j < piles.size(); j++) {
            for (int i = 0; i < piles.size() - j; i++) {
                dp[i][i + j] = std::max(piles[i] - dp[i + 1][i + j], 
                                        piles[i + j] - dp[i][i + j - 1]);
            }
        }
        return dp[0][piles.size() - 1] > 0;
    }
};