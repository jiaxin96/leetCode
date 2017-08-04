/**
 * File: e:\code\leetCode\42-TrappingRainWater\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Thursday, August 3rd 2017, 5:54:23 pm
 * Author: JX
 * -----
 * Last Modified: Sat Aug 05 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int l = height.size();
        if (l <= 2) return 0;
        vector<int> lMax;
        lMax.resize(l);
        vector<int> rMax;
        rMax.resize(l);
        int lm=0, rm=0;
        
        for(int i = 0; i < l; ++i) {
            lMax[i] = lm;
            lm = lm > height[i] ? lm : height[i];
        }
        for(int i = l-1; i >= 0; --i) {
            rMax[i] = rm;
            rm = rm > height[i] ? rm : height[i];
        }
        int ans = 0;
        for (int i = 1; i <= l-2; ++i) {
            int t = (rMax[i] < lMax[i] ? rMax[i] : lMax[i]) - height[i];
            if (t > 0) {
                ans += t;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    cout << s.trap(v);
    return 0;
}
