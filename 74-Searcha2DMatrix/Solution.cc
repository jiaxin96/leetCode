/**
 * File: e:\code\leetCode\74-Searcha2DMatrix\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Friday, August 18th 2017, 12:33:23 am
 * Author: JX
 * -----
 * Last Modified: Fri Aug 18 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        if (r == 0) return false;
        int c = matrix[0].size();
        if (c == 0) return false;
        int b = 0, e = c - 1, m = (c-1)/2;
        int rpos = -1;
        int cpos = -1;
        for (int i = 0; i < r; ++i) {
            if (matrix[i][0] <= target && matrix[i][c-1] >= target) {
                while(b <= e) {
                    m = (b+e)/2;
                    if (matrix[i][m] == target) {
                        // rpos = i;
                        // cpos = m;
                        return true;
                        // break;
                    } else if (matrix[i][m] < target)
                    {
                        b = m + 1;
                    } else {
                        e = m - 1;
                    }
                }
                break;
            }
        }
        return false;
    }
};