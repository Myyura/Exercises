/**
 * Coin sums
 * Myyura
 */

/**
 * In England the currency is made up of pound, £, and pence, p, and there are 
 * eight coins in general circulation:
 * 
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 * It is possible to make £2 in the following way:
 * 
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * How many different ways can £2 be made using any number of coins?
 */

#include <stdio.h>

// Brute-force recursively
void coin_sum_recursively(int *coins, int n, int k, int target, int *count) {
    if (target == 0) { 
        (*count)++; 
        return;
    }

    if (target < 0) { return; }

    for (int i = k; i < n; i++) {
        coin_sum(coins, n, i, target - coins[i], count);
    }
}

/**
 * An DP algorithm.
 * dp[i][j] is the number of ways to make total i using coins of [c1, c2, ... , cj]
 * 
 * hence dp[i][j] = dp[i][j - 1] + dp[i - cj][j].
 */
int coin_sum_dp(int *coins, int n, int target) {
    int dp[target + 1][n];
    for (int i = 0; i <= target; i++) {
        dp[i][0] = 1;
    }

    for (int i = 0; i <= target; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1] + (i - coins[j] >= 0 ? dp[i - coins[j]][j] : 0);
        }
    }

    return dp[target][n - 1];
}

int main(void) {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int count = 0;
    coin_sum_recursively(coins, sizeof(coins)/sizeof(coins[0]), 0, 200, &count);
    printf("%d %d\n", count, coin_sum_dp(coins, sizeof(coins)/sizeof(coins[0]), 200));
    return 0;
}