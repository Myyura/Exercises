/**
 * Single Number II
 * Myyura
 */

/**
 * Given a non-empty array of integers, every element appears three times except 
 * for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement 
 * it without using extra memory?
 * 
 * Example 1:
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * Example 2:
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 */

/**
 * https://leetcode.com/problems/single-number-ii/discuss/151537/c++-bitwise-solution.-O(n)-time-O(1)-space.
 */

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int one = 0, two = 0;
        for (auto n : nums) {
            one = (one ^ n) & ~two;
            two = (two ^ n) & ~one;
        }
        
        return one;
    }
};