/**
 * File: e:\code\leetCode\494.-TargetSum\Solution.cc
 * Project: e:
 * Created Date: Saturday, October 14th 2017, 5:56:35 pm
 * Author: JX
 * -----
 * Last Modified: Sat Oct 14 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int target = 0;
        for (int i = 0; i < nums.size(); ++i) {
            target += nums[i];
        }
        if(S > target || (S+target)%2 != 0) return 0;
        target = (target+S)/2;


        vector<int> dp(target+1, 0);
        dp[0] = 1;
        // 这里是01背包问题的一维数组解法.
        for (int i : nums) {
            for (int j = target; j >= i; --j) {
                dp[j] += dp[j-i];
            }
        }
        return dp[target];
    }
};