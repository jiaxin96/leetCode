/**
 * File: e:\code\leetCode\136-SingleNumber\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Friday, September 22nd 2017, 11:38:25 pm
 * Author: JX
 * -----
 * Last Modified: Fri Sep 22 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int a = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            a = a^nums[i];
        }
        return a;
    }
};