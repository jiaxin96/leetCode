/**
 * File: e:\code\leetCode\48-RotateImage\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, August 9th 2017, 8:43:20 pm
 * Author: JX
 * -----
 * Last Modified: Fri Aug 11 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = matrix.size();
        int b = (l / 2) - 1;
        int it = 1;
        if (l%2==1) {
            b = l / 2;
            it = 0;
        }

        for (int i = b; i >= 0; --i) {
            for (int j = 0; j < it; ++j) {
                int r = i;
                int c = i+j;
                int t = matrix[r][c];
                for (int k = 0; k < 4; ++k) {
                    swap(matrix[c][l-1-r] ,t);
                    int tr = r;
                    int tc = c;
                    r = tc;
                    c = l-1-tr;
                }
            }
            it+=2;
        }
        
    }
    void swap(int & a, int & b) {
        int t = a;
        a = b;
        b = t;
    }
};