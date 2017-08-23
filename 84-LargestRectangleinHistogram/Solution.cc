/**
 * File: e:\code\leetCode\84-LargestRectangleinHistogram\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, August 23rd 2017, 10:46:01 am
 * Author: JX
 * -----
 * Last Modified: Wed Aug 23 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
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