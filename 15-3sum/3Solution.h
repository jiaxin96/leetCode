//
// Created by rjx on 16-9-24.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int h = i + 1;
            int r = nums.size() - 1;
            while (h < r) {
                int aim = nums[h] + nums[r];
                if (aim == -nums[i]) {
                    ans.push_back(vector<int>({nums[i], nums[h], nums[r]}));
                    int sameh = nums[h];
                    int samer = nums[r];
                    while (sameh < nums.size() && sameh == nums[h]) h++;
                    while (r > h && samer == nums[r]) r--;
                } else if (-nums[i] > aim) {
                    h++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};

#endif  // LEETCODE_SOLUTION_H
