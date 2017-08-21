/**
 * File: e:\code\leetCode\75-SortColors\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Friday, August 18th 2017, 7:06:37 pm
 * Author: JX
 * -----
 * Last Modified: Mon Aug 21 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int lb = 0;
        int hb = len-1;
        if (len<=1) return;
        for (int i = lb; i <= hb;) {
            if (nums[i] == 0) {
                swap(nums, i, lb);
                lb++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums, i, hb);
                hb--;
            } else {
                i++;
            }
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};