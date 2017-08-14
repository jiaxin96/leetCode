/**
 * File: e:\code\leetCode\54-SpiralMatrix\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Saturday, August 12th 2017, 9:26:30 pm
 * Author: JX
 * -----
 * Last Modified: Mon Aug 14 2017
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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rl = matrix.size();
        vector<int> ans;
        int cl = 0;
        if (rl > 0)
        {
            cl = matrix[0].size();
        }
        else
        {
            return ans;
        }
        int circles = (min(cl, rl)) / 2;
        int rlc = rl - 1;
        int clc = cl - 1;
        for (int i = 0; i < circles; ++i)
        {
            for (int c = i; c < i + clc; ++c)
            {
                ans.push_back(matrix[i][c]);
            }
            for (int r = i; r < i + rlc; ++r)
            {
                ans.push_back(matrix[r][i + clc]);
            }
            for (int c = i + clc; c >= i + 1; --c)
            {
                ans.push_back(matrix[i + rlc][c]);
            }
            for (int r = i + rlc; r >= i + 1; --r)
            {
                ans.push_back(matrix[r][i]);
            }
            clc -= 2;
            rlc -= 2;
        }
        if (rl % 2 == 1 || cl % 2 == 1)
        {
            if (rl % 2 == 1 && cl % 2 == 1)
            {
                if (rl > cl)
                {
                    for (int i = rl / 2; i < rl / 2 + cl - (rl - 1); ++i)
                    {
                        ans.push_back(matrix[rl / 2][i]);
                    }
                }
                else
                {
                    for (int i = cl / 2; i < cl / 2 + rl - (cl - 1); ++i)
                    {
                        ans.push_back(matrix[i][cl / 2]);
                    }
                }
            }
            else if (rl % 2 == 1)
            {
                for (int i = rl / 2; i < rl / 2 + cl - (rl - 1); ++i)
                {
                    ans.push_back(matrix[rl / 2][i]);
                }
            }
            else if (cl % 2 == 1)
            {
                for (int i = cl / 2; i < cl / 2 + rl - (cl - 1); ++i)
                {
                    ans.push_back(matrix[i][cl / 2]);
                }
            }
        }
        return ans;
    }
};