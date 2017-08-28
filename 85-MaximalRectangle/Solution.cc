/**
 * File: e:\code\leetCode\85-MaximalRectangle\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, August 23rd 2017, 4:40:29 pm
 * Author: JX
 * -----
 * Last Modified: Mon Aug 28 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if (h == 0) return 0;
        int r = matrix[0].size();
        if (r == 0) return 0;
        vector<int> his(r,0);
        int ans = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < r; ++j) {
                his[j] = matrix[i][j] == '0' ? 0 : (his[j] + 1);
            }
            ans = max(ans, largestRectangleArea(his));
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (s.empty() || heights[i] >= s.top()) {
                s.push(heights[i]);
                continue;
            }
            int c = 0;
            while(!s.empty() && heights[i] < s.top()) {
                c++;
                ans = max(ans, s.top()*c);
                s.pop();
            }
            for (int j = 0; j <= c; ++j) {
                s.push(heights[i]);
            }
        }
        int c = 0;
        while(!s.empty()) {
            c++;
            ans = max(ans, s.top()*c);
            s.pop();
        }
        return ans;
    }
};