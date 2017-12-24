/**
 * File: e:\code\leetCode\330-PatchingArray\Solution.cc
 * Project: e:\code\leetCode\330-PatchingArray
 * Created Date: Sunday, December 24th 2017, 1:32:37 pm
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
    int minPatches(vector<int> &nums, int n)
    {
        long miss = 1;
        int ret = 0, i = 0;
        while (miss <= n)
        {
            if (i < nums.size() && nums[i] <= miss)
            {
                miss += nums[i++];
            }
            else
            {
                miss <<= 1;
                ++ret;
            }
        }
        return ret;
    }
};
