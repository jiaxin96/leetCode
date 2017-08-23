/**
 * File: e:\code\leetCode\80-RemoveDuplicatesfromSortedArrayII\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, August 22nd 2017, 8:08:38 pm
 * Author: JX
 * -----
 * Last Modified: Wed Aug 23 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int b = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if(nums[i] != nums[b-2]) {
                nums[b] = nums[i];
                b++;
            }
        }
        return b;
    }
};