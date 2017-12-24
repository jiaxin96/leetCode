/**
 * File: e:\code\leetCode\376-WiggleSubsequence\Solution.cc
 * Project: e:\code\leetCode\376-WiggleSubsequence
 * Created Date: Sunday, December 24th 2017, 1:11:57 am
 * Author: JX
 * -----
 * Last Modified: Sun Dec 24 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution
{
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        if (nums.size() == 2)
        {
            return (nums[0] == nums[1]) ? 1 : 2;
        }
        vector<int> dp(nums.size(), 0);
        vector<int> signs(nums.size(), 0);
        dp[0] = 1;
        int maxl = 1;
        signs[1] = (nums[1] - nums[0] > 0) ? 1 : -1;
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (signs[j] == 0 || signs[j] * (nums[i] - nums[j]) < 0)
                {
                    if (dp[j] + 1 >= dp[i] && nums[i] != nums[j])
                    {
                        dp[i] = max(dp[i], dp[j] + 1);
                        signs[i] = (nums[j] - nums[i] > 0) ? -1 : 1;
                    }
                }
            }
            maxl = max(maxl, dp[i]);
        }
        return maxl;
    }
};

class Solution2
{
  public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int size = nums.size(), f = 1, d = 1;
        for (int i = 1; i < size; ++i)
        {
            if (nums[i] > nums[i - 1])
                f = d + 1;
            else if (nums[i] < nums[i - 1])
                d = f + 1;
        }
        return min(size, max(f, d));
    }
};