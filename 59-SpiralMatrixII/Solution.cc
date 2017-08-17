/**
 * File: e:\code\leetCode\59-SpiralMatrixII\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, August 16th 2017, 12:48:38 am
 * Author: JX
 * -----
 * Last Modified: Wed Aug 16 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rl = n;
        vector<vector<int>> ans(n, vector<int>(n,0));
        // for (int i = 0; i < n; ++i) {
        //     vector<int> t(n,0);
        //     ans[]
        // }
        int cl = n;
        int num = 1;

        if (n==0)
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
                ans[i][c]=num++;
            }
            for (int r = i; r < i + rlc; ++r)
            {
                ans[r][i + clc]=num++;
            }
            for (int c = i + clc; c >= i + 1; --c)
            {
                ans[i + rlc][c]=num++;
            }
            for (int r = i + rlc; r >= i + 1; --r)
            {
                ans[r][i]=num++;
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
                        ans[rl / 2][i]=num++;
                    }
                }
                else
                {
                    for (int i = cl / 2; i < cl / 2 + rl - (cl - 1); ++i)
                    {
                        ans[i][cl / 2]=num++;
                    }
                }
            }
            else if (rl % 2 == 1)
            {
                for (int i = rl / 2; i < rl / 2 + cl - (rl - 1); ++i)
                {
                    ans[rl / 2][i]=num++;
                }
            }
            else if (cl % 2 == 1)
            {
                for (int i = cl / 2; i < cl / 2 + rl - (cl - 1); ++i)
                {
                    ans[i][cl / 2]=num++;
                }
            }
        }
        return ans;
    }
};