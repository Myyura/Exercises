/**
 * Edit Distance
 * Myyura
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