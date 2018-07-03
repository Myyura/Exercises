/**
 * Find the Duplicate Number
 * Myyura
 */

/**
 * Given an array nums containing n + 1 integers where each integer is between 
 * 1 and n (inclusive), prove that at least one duplicate number must exist. 
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * Example 1:
 * Input: [1,3,4,2,2]
 * Output: 2
 * 
 * Example 2:
 * Input: [3,1,3,4,2]
 * Output: 3
 * 
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n^2).
 * There is only one duplicate number in the array, but it could be repeated more
 * than once.
 */

class Solution {
public:
    /**
     * If there is no duplicate number, then we have exactly (1 + n) / 2 numbers
     * that are smaller than (or equal to) (1 + n) / 2.
     * 
     * Hence if we find less than (1 + n) / 2 numbers that are smaller than (or 
     * equal to) (1 + n) / 2, then we know that the duplicate number is greater
     * than (1 + n) / 2.
     * 
     * Based on the idea above we can develop a binary search algorithm to find
     * the duplicate number.
     */
    int findDuplicate(std::vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        for (; left < right;) {
            int mid = (left + right) / 2;
            int count = 0;
            for (auto& it : nums) {
                if (it <= mid) { count++; }
            }

            if (count <= mid) { 
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    /**
     * And there is an O(n) algorithm based on Floyd Cycle Detection Algorithm.
     * https://en.wikipedia.org/wiki/Cycle_detection
     * 
     * p[1] -> p[3] -> ... -> p[A] -> ... -> p[B] -> ... p[A]
     * Suppose that hare is 2 times the speed of tortoise and they met at
     * position B.
     * 
     * length from 1 to A: a, length from A to B : b, length of cycle A : L, 
     * then we have 2(a + (pL + b)) = a + (qL + b)
     *                        a + b = (q - 2p)L
     *                            a = (q - 2p)L - b 
     * where q and p are integers.
     * Hence the length a is equal to (q - 2p)L - b. Since tortoise now is in B,
     * after running (q - 2p)L - b long, it will be at position A. With the fact
     * that a is the length from 1 to A, if there is another tortoise in position
     * 1 and start to run when hare and former tortoise met, the two tortoises
     * will meet at A finally.
     */
    int findDuplicate(std::vector<int>& nums) {
        int hare = 0, tortoise = 0;
        hare = nums[nums[hare]];
        tortoise = nums[tortoise];
        for (; hare != tortoise;) {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }

        hare = 0;
        for (; hare != tortoise;) {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        
        return hare;
    }
};