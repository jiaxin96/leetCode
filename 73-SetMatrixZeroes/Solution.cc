/**
 * File: e:\code\leetCode\73-SetMatrixZeroes\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Thursday, August 17th 2017, 9:44:50 pm
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
    void setZeroes(vector<vector<int>>& matrix) {
        int row0 = 1;
        int r = (int)matrix.size();
        if (r == 0) return;
        int c = (int)matrix[0].size();
        for (int j = 0; j < c; ++j) {
            if (matrix[0][j] == 0) row0 = 0;
            for (int i = 1; i < r; ++i) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int j = c-1; j >= 0; --j) {
            for (int i = r-1; i >= 1; --i) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if (row0 == 0) matrix[0][j] = 0;
        }
    }
};