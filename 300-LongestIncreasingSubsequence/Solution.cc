/**
 * File: e:\code\leetCode\300-LongestIncreasingSubsequence\Solution.cc
 * Project: e:
 * Created Date: Wednesday, November 29th 2017, 9:35:08 pm
 * Author: JX
 * -----
 * Last Modified: Fri Dec 01 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};