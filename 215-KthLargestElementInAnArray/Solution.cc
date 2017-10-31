/**
 * File: e:\code\leetCode\215-KthLargestElementInAnArray\Solution.cc
 * Project: e:
 * Created Date: Monday, October 30th 2017, 1:56:29 pm
 * Author: JX
 * -----
 * Last Modified: Tue Oct 31 2017
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
    int findKthLargest(vector<int> &nums, int k)
    {
        return helper(nums, 0, nums.size() - 1, k - 1);
    }

    int helper(vector<int> &nums, int b, int e, int k)
    {
        int l = b, r = e;

        int m = nums[(l + r) / 2];
        while (l <= r)
        {
            while (nums[l] > m)
            {
                l++;
            }
            while (nums[r] < m)
            {
                r--;
            }
            if (l <= r)
            {
                int t = nums[r];
                nums[r] = nums[l];
                nums[l] = t;
                l++;
                r--;
            }
        }
        if (r >= b && k <= r)
            return helper(nums, b, r, k);
        if (l <= e && k >= l)
            return helper(nums, l, e, k);
        return nums[k];
    }
};