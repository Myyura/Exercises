/**
 * Triangle
 * Myyura
 */

/**
 * Given a triangle, find the minimum path sum from top to bottom. Each step you 
 * may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is 
 * the total number of rows in the triangle.
 */

int min(int a, int b) { return a > b ? b : a; }

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    int minPath[triangleRowSize][triangleRowSize];
    for (int i = 0; i < triangleRowSize; i++) {
        for (int j = 0; j < triangleRowSize; j++) {
            minPath[i][j] = 9999999;
        }
    }
    
    minPath[0][0] = triangle[0][0];
    for (int i = 1; i < triangleRowSize; i++) {
        for (int j = 0; j < triangleColSizes[i]; j++) {
            int temp1 = 9999999, temp2 = 9999999;
            if (j > 0) { temp1 = minPath[i - 1][j - 1] + triangle[i][j]; }
            if (j < triangleColSizes[i]) { temp2 = minPath[i - 1][j] + triangle[i][j]; }
            minPath[i][j] = min(temp1, temp2);
        }
    }

    int result = 9999999;
    for (int i = 0; i < triangleColSizes[triangleRowSize - 1]; i++) {
        result = min(result, minPath[triangleRowSize - 1][i]);
    }

    return result;
}