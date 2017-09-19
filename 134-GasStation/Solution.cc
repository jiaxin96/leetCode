/**
 * File: e:\code\leetCode\134-GasStation\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, September 19th 2017, 6:53:05 pm
 * Author: JX
 * -----
 * Last Modified: Tue Sep 19 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int l = gas.size();
        if (l <= 0) return -1;
        
        int s = 0;
        int curSum = 0;
        int b = 0 ,total = 0;
        for (int i = 0; i < l; ++i) {
            curSum += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            
            if (curSum >= 0) {
                
            } else {
                b = i+1;
                curSum = 0;
            }
        }
        
        if (total >= 0) return b;
        else return -1;
    }
};