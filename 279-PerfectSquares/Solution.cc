/**
 * File: e:\code\leetCode\279-PerfectSquares\Solution.cc
 * Project: e:
 * Created Date: Wednesday, October 25th 2017, 11:53:13 pm
 * Author: JX
 * -----
 * Last Modified: Thu Oct 26 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */
#include <math.h>

class Solution {
public:
    int numSquares(int n) {
        int maxPow = int(sqrt(float(n)));
        int *dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            maxPow = int(sqrt(float(i)));
            int t = INT32_MAX;
            for (int j = 1; j <= maxPow; ++j) {
                t=min(t,dp[i-j*j]);
            }
            dp[i] = t+1;
        }
        int ans = dp[n];
        delete [] dp;
        return ans; 
    }
};