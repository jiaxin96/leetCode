/**
 * File: e:\code\leetCode\321-CreateMaximumNumber\Solution.cc
 * Project: e:\code\leetCode\321-CreateMaximumNumber
 * Created Date: Sunday, December 24th 2017, 3:52:49 pm
 * Author: JX
 * -----
 * Last Modified: Sun Dec 24 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution
{
    int findMaximizedCapital(int k, int W, vector<int> &P, vector<int> &C)
    {
        priority_queue<int> low;
        multiset<pair<int, int>> high;

        for (int i = 0; i < P.size(); ++i)
        {
            if (P[i] > 0)
                if (C[i] <= W)
                    low.push(P[i]);
                else
                    high.emplace(C[i], P[i]);
        }

        while (k-- && low.size())
        {
            W += low.top(), low.pop(); // greedy to work on most profitable first
            for (auto i = high.begin(); high.size() && i->first <= W; i = high.erase(i))
                low.push(i->second);
        }
        return W;
    }
};