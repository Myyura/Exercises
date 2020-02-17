/**
 * Myyura
 */

/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 *
 * https://leetcode.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (67.14%)
 * Likes:    416
 * Dislikes: 30
 * Total Accepted:    40.1K
 * Total Submissions: 59.6K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all
 * elements in arr2 are also in arr1.
 * 
 * Sort the elements of arr1 such that the relative ordering of items in arr1
 * are the same as in arr2.  Elements that don't appear in arr2 should be
 * placed at the end of arr1 in ascending order.
 * 
 * Example 1:
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 * 
 * Constraints:
 * arr1.length, arr2.length <= 1000
 * 0 <= arr1[i], arr2[i] <= 1000
 * Each arr2[i] is distinct.
 * Each arr2[i] is in arr1.
 */

// @lc code=start
class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
        std::vector<int> sorted(arr1.size());
        int k = 0;
        for (int i = 0; i < arr2.size();) {
            bool found = false;
            for (int j = 0; j < arr1.size(); j++) {
                if (arr1[j] == arr2[i]) {
                    found = true;
                    sorted[k++] = arr2[i];
                    arr1[j] = -1;
                }
            }

            if (!found) { i++; }
        }

        for (int i = 0, j = k; i < arr1.size(); i++) {
            if (arr1[i] != -1) {
                sorted[j++] = arr1[i];
            }
        }

        std::sort(sorted.begin() + k, sorted.end());
        return sorted;
    }
};
// @lc code=end

