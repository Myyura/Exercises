/**
 * Sort Colors
 * Myyura
 */

/**
 * Given an array with n objects colored red, white or blue, sort them in-place 
 * so that objects of the same color are adjacent, with the colors in the order 
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
 * and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this problem.
 * 
 * Example:
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite 
 * array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 */

class Solution {
public:
    /**
     * We wanna put zeros in the left, twos in the right, then suppose that we
     * somehow sort our array partly in the following form, where * represents
     * the elements that we have not sorted yet.
     * 0...011...1***2...2
     *     |     |  |
     *   left   i  right
     * 
     * if * in i is 0, swap(left, i), left++, i++
     * 
     * if * in i is 1, i++
     * 
     * if * in i is 2, then we need check the * in right.
     *  - if the * in right is 2, then right--
     *  - if the * in right is 1 or 0 (for example 0), then swap(i, right), right--
     */
    void sortColors(std::vector<int>& nums) {
        for (int left = 0, right = nums.size() - 1, i = 0; i <= right;) {
            if (nums[i] == 0) {
                nums[i++] = nums[left];
                nums[left++] = 0;
            } else if (nums[i] == 2) {
                if (nums[right] == 2) { right--; }
                else {
                    nums[i] = nums[right];
                    nums[right--] = 2;
                }
            } else if (nums[i] == 1) { i++; }
        }
    }
};