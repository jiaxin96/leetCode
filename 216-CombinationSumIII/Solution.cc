/**
 * File: e:\code\leetCode\216-CombinationSumIII\Solution.cc
 * Project: e:
 * Created Date: Monday, November 20th 2017, 9:52:40 am
 * Author: JX
 * -----
 * Last Modified: Mon Nov 20 2017
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
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(k, 1, n,ans,temp);
        return ans;
    }
    void helper(int k, int b,int n, vector<vector<int>>& ans, vector<int>& temp) {
        if (n == 0 && k == 0) {
            ans.push_back(temp);
            return;
        }
        if (n <= 0 || k <= 0) {
            return;
        }
        for (int i = b; i <= n; ++i) {
            if (i > 9) continue;
            temp.push_back(i);
            helper(k-1, i+1, n-i, ans, temp);
            temp.pop_back();
        }
    }
};