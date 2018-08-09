/**
 * Projection Area of 3D Shapes
 * Myyura
 */

/**
 * On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the 
 * x, y, and z axes.
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of grid 
 * cell (i, j).
 * Now we view the projection of these cubes onto the xy, yz, and zx planes.
 * A projection is like a shadow, that maps our 3 dimensional figure to a 2 
 * dimensional plane. 
 * Here, we are viewing the "shadow" when looking at the cubes from the top, the 
 * front, and the side.
 * Return the total area of all three projections.
 * 
 * Example 1:
 * Input: [[2]]
 * Output: 5
 * 
 * Example 2:
 * Input: [[1,2],[3,4]]
 * Output: 17
 * 
 * Example 3:
 * Input: [[1,0],[0,2]]
 * Output: 8
 * 
 * Example 4:
 * Input: [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 14
 * 
 * Example 5:
 * Input: [[2,2,2],[2,1,2],[2,2,2]]
 * Output: 21
 *  
 * Note:
 * 1 <= grid.length = grid[0].length <= 50
 * 0 <= grid[i][j] <= 50
 */

class Solution {
public:
    int projectionArea(std::vector<std::vector<int>>& grid) {
        int xy = 0, xz = 0, yz = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) { xy += 1; }
            }
        }
        
        for (int i = 0; i < grid.size(); i++) {
            int max_i = 0;
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) { max_i = std::max(grid[i][j], max_i); }
            }
            xz += max_i;
        }
        
        for (int j = 0; j < grid.size(); j++) {
            int max_j = 0;
            for (int i = 0; i < grid[0].size(); i++) {
                if (grid[i][j] > 0) { max_j = std::max(grid[i][j], max_j); }
            }
            yz += max_j;
        }
        
        return xy + xz + yz;
    }
};