//
// Created by rjx on 16-9-25.
//

// Describe
// Given an array S of n integers, are there elements a, b, c, and d in S
// such that a + b + c + d = target? Find all unique quadruplets in the array
// which gives the sum of target.
#ifndef LEETCODE_4SOLUTION_H
#define LEETCODE_4SOLUTION_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j != i + 1 && nums[j - 1] == nums[j]) continue;
                int h = j + 1, r = nums.size() - 1;
                int aim = target - nums[i] - nums[j];
                while (h < r) {
                    int temp = nums[h] + nums[r];
                    if (temp == aim) {
                        ans.push_back(vector<int>({nums[i], nums[j], nums[h], nums[r]}));
                        int sameh = nums[h];
                        int samer = nums[r];
                        while (h < nums.size() - 1 && sameh == nums[h]) h++;
                        while (r > h && nums[r] == samer) r--;
                    } else if (temp > aim) {
                        r--;
                    } else {
                        h++;
                    }
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODE_4SOLUTION_H
