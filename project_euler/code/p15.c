/* Lattice paths */
/* Myyyura */

#include <stdio.h>
#include <stdint.h>

/*
    https://en.wikipedia.org/wiki/Lattice_path
    C(n, 2n)
*/

int64_t num_lattice_paths_combinatorial(int n) {
    int64_t result = 1;
    for (int i = n + 1, j = 1; i <= 2 * n; i++, j++) {
        result *= i;
        result /= j;
    }

    return result;
}

/*
    To get to position [i, j] in one step, we must already in position 
    [i - 1, j] or [i, j - 1].
*/

int64_t num_lattice_paths_dp(int n) {
    int64_t grid[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        grid[0][i] = 1;
        grid[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        }
    }

    return grid[n][n];
}

int main(void) {
    printf("%lld\n", num_lattice_paths_combinatorial(20));
    printf("%lld\n", num_lattice_paths_dp(20));
    return 0;
}