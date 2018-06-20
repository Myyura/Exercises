/**
 * Trapping Rain Water
 * Myyura
 */

/**
 * Given n non-negative integers representing an elevation map where the width 
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In 
 * this case, 6 units of rain water (blue section) are being trapped.
 * 
 * Example:
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */

class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftWall = 0, rightWall = 0, water = 0;
        for (; left <= right;) {
            if (leftWall <= rightWall) {
                leftWall = std::max(leftWall, height[left]);
                water += leftWall - height[left++];
            } else {
                rightWall = std::max(rightWall, height[right]);
                water += rightWall - height[right--];
            }
        }

        return water;
    }
};