/**
 * File: e:\code\leetCode\52-N-QueensII\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Saturday, August 12th 2017, 9:19:07 pm
 * Author: JX
 * -----
 * Last Modified: Sat Aug 12 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        string row(n,'.');
        vector<string> temp(n,row);
        helper(ans,1,temp,n);
        return ans;
    }
    void helper(int & ans, int row, vector<string> & temp, int n) {
        if (row == n+1) {
            ans++;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (canPut(temp, row-1, i, n)) {
                temp[row-1][i] = 'Q';
                helper(ans,row+1,temp, n);
                temp[row-1][i] = '.';                
            }
        }
    }
    bool canPut(vector<string> & temp, int row, int col, int n) {
        for (int i = 0; i < n; ++i) {
            if (temp[row][i] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (temp[i][col] == 'Q') {
                return false;
            }
        }
        int i, j;
        for (i = row, j = col; j < n && i < n; ++j, ++i) {
            if (temp[i][j] == 'Q') {
                return false;
            }
        }
        for (i = row, j = col; j >= 0 && i >= 0; --j, --i) {
            if (temp[i][j] == 'Q') {
                return false;
            }
        }
        for (i = row, j = col; j < n && i >= 0; ++j, --i) {
            if (temp[i][j] == 'Q') {
                return false;
            }
        }
        for (i = row, j = col; j >= 0 && i < n; --j, ++i) {
            if (temp[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
