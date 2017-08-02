/**
 * File: e:\code\leetCode\39-CombinationSum\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, August 1st 2017, 10:41:00 pm
 * Author: JX
 * -----
 * Last Modified: Wed Aug 02 2017
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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
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
        for (int i = pos; i < candidates.size(); ++i)
        {
            int c = target / candidates[i] + 1;
            for (int k = 1; k <= c; ++k)
            {
                for (int j = 0; j < k; ++j)
                {
                    tempans.push_back(candidates[i]);
                }
                dfs(ans, tempans, candidates, target - k * candidates[i], i + 1);
                for (int j = 0; j < k; ++j)
                {
                    tempans.pop_back();
                }
            }
        }
    }
};

int main()
{

    return 0;
}