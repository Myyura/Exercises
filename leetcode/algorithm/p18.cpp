/**
 * 4Sum
 * Myyura
 */

class Solution {
public:
    // Same idea as 3Sum Closest (problem 16)
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i && nums.at(i) == nums.at(i - 1)) {
                continue;
            }

            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums.at(j) == nums.at(j - 1)) {
                    continue;
                }

                int currentTarget = target - nums.at(i) - nums.at(j);
                for (int left = j + 1, right = nums.size() - 1; left < right;) {
                    int sum = nums.at(left) + nums.at(right);
                    if (sum < currentTarget) {
                        left++;
                    }

                    if (sum > currentTarget) {
                        right--;
                    }

                    if (sum == currentTarget) {
                        std::vector<int> temp = {nums.at(i), nums.at(j), nums.at(left), nums.at(right)};
                        result.push_back(temp);
                        
                        for (left++; left < right && nums.at(left) == nums.at(left - 1); left++)
                            ;
                        
                        for (right--; right > left && nums.at(right) == nums.at(right + 1); right--)
                            ;
                    }
                }
            }
        }

        return result;
    }
};