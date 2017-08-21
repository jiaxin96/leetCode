/**
 * File: e:\code\leetCode\77-Combinations\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Monday, August 21st 2017, 10:34:27 am
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
    vector<vector<int>> combine(int n, int k) {
        vector<int> t;
        vector<vector<int>> ans;
        helper(ans, t, k, n, 1);
        return ans;
    }
    void helper(vector<vector<int>> & ans, vector<int> & temp, int k, int n, int pos) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for (int i = pos; i <= n; ++i) {
            temp.push_back(i);
            helper(ans,temp,k,n,i+1);
            temp.pop_back();
        }
    }
};