/**
 * File: e:\code\leetCode\93-RestoreIPAddresses\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, August 29th 2017, 2:10:55 pm
 * Author: JX
 * -----
 * Last Modified: Wed Aug 30 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string tip = "";
        vector<string> ans;
        if (s.length() < 4 || s.length() > 12) return ans;
        getAns(s,0, 0, tip, ans);
        return ans;
    }
    void getAns(string s, int start, int step, string ip, vector<string> & ans) {
        if (s.length()-start > (4-step)*3)
            return;
        if (s.length()-start < (4-step))
            return;
        if (start == s.length() && step == 4) {
            ip.resize(ip.length() - 1);
            ans.push_back(ip);
            return;
        }
        int num = 0;
        for (int i = start; i < start+3; ++i) {
            num = num*10 + (s[i]-'0');
            if(num<=255) {
                ip += s[i];
                getAns(s,i+1,step+1,ip+'.',ans);
            }
            if (num == 0) break; // 不许前缀名
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
