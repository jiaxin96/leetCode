/**
 * File: e:\code\leetCode\55-JumpGame\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Monday, August 14th 2017, 11:47:57 pm
 * Author: JX
 * -----
 * Last Modified: Tue Aug 15 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = -1;
        int next = 0;
        for (int i = 0; i < nums.size(); ++i) {
            next = next > nums[i] + i ? next : nums[i] + i;
            
            if (i > reach) {
                reach = next;
            }
            if (i == nums.size() - 1) return true;
            if (i >= next) {
                return false;
            }

        }
        return true;
    }
};