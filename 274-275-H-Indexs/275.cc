/**
 * File: e:\code\leetCode\274-275-H-Indexs\275.cc
 * Project: e:
 * Created Date: Monday, November 20th 2017, 2:43:14 pm
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

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int end = 0, begin = n - 1;
        int h = 0;
        while (end <= begin)
        {
            int middle = begin + (end - begin) / 2;
            if (citations[middle] >= n - middle)
            {
                end = middle - 1;
                h = n - middle;
            }
            else
                begin = middle + 1;
        }
        return h;
    }
};
