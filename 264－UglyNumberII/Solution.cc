/**
 * File: e:\code\leetCode\264－UglyNumberII\Solution.cc
 * Project: e:
 * Created Date: Monday, November 20th 2017, 10:48:49 am
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
    int nthUglyNumber(int n)
    {
        vector<int> results(1, 1);
        int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
            if (results.back() == results[i] * 2)
                ++i;
            if (results.back() == results[j] * 3)
                ++j;
            if (results.back() == results[k] * 5)
                ++k;
        }
        return results.back();
    }
};