/**
 * Edit Distance
 * Myyura
 */

/**
 * Given two words word1 and word2, find the minimum number of operations 
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * Example 1:
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * Example 2:
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 */

/**
 * Wagner–Fischer algorithm
 * https://en.wikipedia.org/wiki/Wagner%E2%80%93Fischer_algorithm
 */

int insCost(char a) {
    return 1;
}

int delCost(char a) {
    return 1;
}

int substCost(char a, char b) {
    if(a == b) {
        return 0;
    } else {
        return 1;
    }
}

int min(int x, int y, int z) {
    if(x <= y && x <= z) {
        return x;
    } else if(y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}

int minDistance(char *word1, char *word2) {
    int n = strlen(word1);
    int m = strlen(word2);
    int distance[n + 1][m + 1];

    distance[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        distance[i][0] = distance[i - 1][0] + insCost(word1[i]);
    }

    for(int j = 1; j <= m; j++) {
        distance[0][j] = distance[0][j - 1] + delCost(word2[j]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            distance[i][j] = min(distance[i - 1][j] + insCost(word1[i - 1]), \
                distance[i - 1][j - 1] + substCost(word2[j - 1], word1[i - 1]), \
                distance[i][j - 1] + delCost(word2[j - 1]));
        }
    }

    return distance[n][m];
}