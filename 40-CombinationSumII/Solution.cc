/**
 * File: e:\code\leetCode\40-CombinationSumII\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, August 2nd 2017, 9:47:51 pm
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

#include <algorithm>
#include <vector>
class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tempans;
        dfs(ans, tempans, candidates, target, 0);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &tempans, vector<int> &candidates, int target, int pos)
    {
        if (target == 0)
        {
            ans.push_back(tempans);
            return;
        }
        if (pos > candidates.size() - 1 || target < 0)
        {
            return;
        }


        for (int i = pos; i < candidates.size(); ++i) {
            if (i != pos && candidates[i-1] == candidates[i]) continue;
            tempans.push_back(candidates[i]);
            dfs(ans, tempans, candidates, target - candidates[i], i + 1);
            tempans.pop_back();
        }
    }
};
