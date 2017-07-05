//
// Created by rjx on 16-9-25.
//
// Describe
// Given an array S of n integers, find three integers in S
// such that the sum is closest to a given number, target.
// Return the sum of the three integers. You may assume that
// each input would have exactly one solution.
//For example, given array S = {-1 2 1 -4}, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#ifndef LEETCODE_3SUMCLOSEST_H
#define LEETCODE_3SUMCLOSEST_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int temadd = target, temsub = target;
        int k = 1, temp;
        while (k++) {
            if (k == 2) {
                temp = target;
            } else if (k % 2) {
                temadd++;
                temp = temadd;
            } else {
                temsub--;
                temp = temsub;
            }
            for (int i = 0; i < nums.size() - 2; ++i) {
                if (i > 0 && nums[i - 1] == nums[i]) continue;
                int h = i + 1;
                int r = nums.size() - 1;
                while (h < r) {
                    int aim = nums[h] + nums[r] - temp;
                    if (aim == -nums[i]) {
                        return nums[i] + nums[h] + nums[r];
                    } else if (-nums[i] > aim) {
                        h++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return 0;
    }
};

#endif //LEETCODE_3SUMCLOSEST_H
