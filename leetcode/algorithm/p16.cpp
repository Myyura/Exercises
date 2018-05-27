/**
 * 3Sum Closest
 * Myyura
 */

class Solution {
public:
    int myAbs(int n) {
        return n >= 0 ? n : -n;
    }
    
    int threeSumClosest(std::vector<int>& nums, int target) {
        int result;
        int diff = std::numeric_limits<int>::max();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int curTarget = target - nums.at(i);
            for (int left = i + 1, right = nums.size() - 1; left < right;) {
                int curSum = nums.at(left) + nums.at(right);
                if (diff > myAbs(curTarget - curSum)) {
                    result = nums.at(i) + nums.at(left) + nums.at(right);
                    diff = myAbs(curTarget - curSum);
                }

                if (curSum < curTarget) {
                    left++;
                }
                
                if (curSum > curTarget) {
                    right--;
                }

                if (curSum == curTarget) {
                    return result;
                }
            }
        }

        return result;
    }
};