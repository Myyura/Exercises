/**
 * Container With Most Water
 * Myyura
 */

/**
 * Given n non-negative integers a1, a2, ..., an, where each represents a point 
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
 * of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
 * forms a container, such that the container contains the most water.
 * 
 * Note: You may not slant the container and n is at least 2.
 */

class Solution {
public:
    // Brute-force TLE
    int maxAreaBruteForce(std::vector<int>& height) {
        int maxSize = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int smallOne = height.at(i) < height.at(j) ? height.at(i) : height.at(j);
                int curSize = (j - i) * smallOne;
                maxSize = curSize > maxSize ? curSize : maxSize;
            }
        }

        return maxSize;
    }

    /**
     * Basic idea;
     * Suppose that we are finding the maximum size of container in [i, j] and
     * a_i < a_j.
     * 
     * If a_i > a_{i + 1}, then the maximum container that uses a_{i + 1} will 
     * smaller than the maximum container that uses a_i.
     */
    int maxArea(std::vector<int>& height) {
        int maxSize = 0;
        for (int left = 0, right = height.size() - 1; left < right;) {
            if (height.at(left) <= height.at(right)) {
                int containerSize = (right - left) * height.at(left);
                left++;
                maxSize = maxSize > containerSize ? maxSize : containerSize;
            } else {
                int containerSize = (right - left) * height.at(right);
                right--;
                maxSize = maxSize > containerSize ? maxSize : containerSize;
            }
        }

        return maxSize;
    }

    // First version ... ugly version
    int maxAreaUgly(std::vector<int>& height) {
        int maxSize = 0;
        for (int left = 0, right = height.size() - 1; left < right;) {
            int curSize = (right - left) * std::min(height.at(left), height.at(right));
            if (height.at(left) <= height.at(right)) {
                for (; left <= right; left++) {
                    int containerSize = (right - left) * height.at(left);
                    if (curSize < containerSize) {
                        break;
                    }
                }
            } else {
                for (; right >= left; right--) {
                    int containerSize = (right - left) * height.at(right);
                    if (curSize < containerSize) {
                        break;
                    }
                }
            }

            maxSize = curSize > maxSize ? curSize : maxSize;
        }

        return maxSize;
    }
};