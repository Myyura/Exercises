#include <string.h>

static int ins_cost(char a) {
    return 1;
}

static int del_cost(char a) {
    return 1;
}

static int subst_cost(char a, char b) {
    if(a == b) {
        return 0;
    } else {
        return 2;
    }
}

static int min(int x, int y, int z) {
    if(x <= y && x <= z) {
        return x;
    } else if(y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}

int min_edit_distance(char *target, char *source) {
    int n = strlen(target);
    int m = strlen(source);
    int distance[n + 1][m + 1];

    // initialize the zeroth row and column to be the distance from empty string
    distance[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        distance[i][0] = distance[i - 1][0] + ins_cost(target[i]);
    }

    for(int j = 1; j <= m; j++) {
        distance[0][j] = distance[0][j - 1] + del_cost(source[j]);
    }

    // calculate minimum edit distance with dynamic programming
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            distance[i][j] = min(distance[i - 1][j] + ins_cost(target[i - 1]), \
                distance[i - 1][j - 1] + subst_cost(source[j - 1], target[i - 1]), \
                distance[i][j - 1] + del_cost(source[j - 1]));
        }
    }

    return distance[n][m];
}
