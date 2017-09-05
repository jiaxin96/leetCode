/**
 * File: e:\code\leetCode\81-SearchinRotatedSortedArrayII\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, September 5th 2017, 3:39:27 pm
 * Author: JX
 * -----
 * Last Modified: Tue Sep 05 2017
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
     bool search(vector<int> &nums, int target)
     {
         int n = nums.size();
         int pre = 0, pos = n - 1;
         int mid = 0;
         while (pre <= pos)
         {
             mid = (pre + pos) / 2;
             if (nums[mid] == target)
                 return true;
             if (nums[mid] > nums[pos])
             {
                 if (nums[mid] > target && nums[pre] <= target)
                     pos = mid-1;
                 else
                     pre = mid + 1;
             }
             else if (nums[mid] < nums[pos])
             {
                 if (nums[mid] < target && nums[pos] >= target)
                     pre = mid + 1;
                 else
                     pos = mid-1;
             }
             else
             {
                 pos--;
             }
         }
         // return nums[pre] == target ? true : false;
         return false;
     }
 };