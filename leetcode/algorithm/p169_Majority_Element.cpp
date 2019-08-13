/**
 * Majority Element
 * Myyura
 */

/**
 * Given an array of size n, find the majority element. The majority element 
 * is the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always 
 * exist in the array.
 * 
 * Example 1:
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 */

/* O(nlogn) */
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

/* O(n) */
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> count;
        int maxCount = 0, majority = -1;
        for (const auto& it : nums) {
            count.count(it) == 0 ? count[it] = 1 : count[it]++;
            if (count[it] > maxCount) {
                maxCount = count[it], majority = it;
            }
        }
        
        return majority;
    }
};

/* O(n) */
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int count = 0, majority = -1;
        for (const auto& it : nums) {
            if (count == 0) { 
                majority = it;
                count++; 
            } else {
                majority == it ? count++ : count--;
            }
        }
        
        return majority;
    }
};