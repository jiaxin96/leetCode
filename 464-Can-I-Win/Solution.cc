/**
 * File: e:\code\leetCode\464-Can-I-Win\Solution.cc
 * Project: e:
 * Created Date: Monday, October 9th 2017, 11:31:38 pm
 * Author: JX
 * -----
 * Last Modified: Mon Oct 09 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
private:
    int maxn;
    map<int, bool> m;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxn = maxChoosableInteger;
        if(maxn >= desiredTotal) return true;
        if((1 + maxn) * maxn / 2 < desiredTotal) return false;
        return canWin(desiredTotal, 0);
    }
    bool canWin(int target, int visited) {
        if(m.find(visited) != m.end()) return m[visited];
        for(int i = 1; i <= maxn; i++) {
            int mask = (1 << i);
            if((mask & visited) == 0 && (i >= target || canWin(target - i, mask | visited) == false)) {
                m[visited] = true;
                return true;
            }
        }
        m[visited] = false;
        return false;
    }
};