/* Maximum path sum */
/* Myyyura */

#include <stdio.h>

int triangle[100][100] = {-1};
int max_path[100][100] = {-1};

int read_data(FILE* input) {
    char buffer[1000];
    int lines = 0;
    while (fgets(buffer, 1000, input) != NULL) {
        lines++;
        for (int j = 0; j < lines; j++) {
            sscanf(buffer + j * 3, "%d", &triangle[lines - 1][j]);
        }
    }

    return lines;
}

int max(int a, int b) {
    return a > b ? a : b;
}

/*
    To get to position [i, j] in one step, we must already in position 
    [i - 1, j - 1] or [i - 1, j].
*/
int maximum_path_sum_dp(int n) {
    max_path[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int temp1 = 0, temp2 = 0;
            if (j > 0) {
                temp1 = max_path[i - 1][j - 1] + triangle[i][j];
            }

            if (j < i) {
                temp2 = max_path[i - 1][j] + triangle[i][j];
            }

            max_path[i][j] = max(temp1, temp2);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, max_path[n - 1][i]);
    }

    return result;
}

int main(void) {
    FILE *data_18 = fopen("../../data/p18.txt", "r");
    int line_18 = read_data(data_18);
    fclose(data_18);

    FILE *data_67 = fopen("../../data/p67.txt", "r");
    int line_67 = read_data(data_67);
    fclose(data_67);

    printf("p18: %d\n", maximum_path_sum_dp(line_18));
    printf("p67: %d\n", maximum_path_sum_dp(line_67));
    return 0;
}