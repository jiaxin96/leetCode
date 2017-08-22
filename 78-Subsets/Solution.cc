/**
 * File: e:\code\leetCode\78-Subsets\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, August 22nd 2017, 7:34:24 pm
 * Author: JX
 * -----
 * Last Modified: Tue Aug 22 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        vector<vector<int>> ans;
        int l = nums.size();
        for (int i = 0; i <= l; ++i) {
            helper(ans, t, i, l-1, 0, nums);
        }
        return ans;
    }
    void helper(vector<vector<int>> & ans, vector<int> & temp, int k, int n, int pos, vector<int>& nums) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for (int i = pos; i <= n; ++i) {
            temp.push_back(nums[i]);
            helper(ans,temp,k,n,i+1, nums);
            temp.pop_back();
        }
    }
};