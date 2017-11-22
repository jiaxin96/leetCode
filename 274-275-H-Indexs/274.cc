/**
 * File: e:\code\leetCode\274-275-H-Indexs\274.cc
 * Project: e:
 * Created Date: Monday, November 20th 2017, 11:26:04 am
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
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); ++i)
        {
            int lef = citations.size() - i;
            if (citations[i] >= lef)
            {
                return lef;
            }
        }
        return 0;
    }
};
