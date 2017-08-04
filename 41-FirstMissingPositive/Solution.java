/**
 * File: e:\code\leetCode\41-FirstMissingPositive\Solution.java
 * Project: e:\code\leetCode
 * Created Date: Thursday, August 3rd 2017, 1:05:15 pm
 * Author: JX
 * -----
 * Last Modified: Thu Aug 03 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */
public class Solution {
    public int firstMissingPositive(int[] nums) {
        int l = nums.length;
        for (int i = 0; i < l; ++i) {
            while (nums[i] > 0 && nums[i] != i + 1 && nums[i] <= l && nums[nums[i]-1] != nums[i]) {
                int t = nums[i];
                nums[i] = nums[t-1];
                nums[t-1] = t;
            }
        }
        for (int i = 0; i < l; ++i) {
            if (nums[i] != i+1) {
                return  i+1;
            }
        }
        return l+1;
    }
}