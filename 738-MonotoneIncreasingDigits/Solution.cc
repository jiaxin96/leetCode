/**
 * File: e:\code\leetCode\738-MonotoneIncreasingDigits\Solution.cc
 * Project: e:\code\leetCode\738-MonotoneIncreasingDigits
 * Created Date: Saturday, December 30th 2017, 10:50:42 pm
 * Author: JX
 * -----
 * Last Modified: Sun Dec 31 2017
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
    int monotoneIncreasingDigits(int N)
    {
        string n_str = to_string(N);

        int marker = n_str.size();
        for (int i = n_str.size() - 1; i > 0; i--)
        {
            if (n_str[i] < n_str[i - 1])
            {
                marker = i;
                n_str[i - 1] = n_str[i - 1] - 1;
            }
        }

        for (int i = marker; i < n_str.size(); i++)
            n_str[i] = '9';

        return stoi(n_str);
    }
};