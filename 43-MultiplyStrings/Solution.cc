/**
 * File: e:\code\leetCode\43-MultiplyStrings\Solution.java
 * Project: e:\code\leetCode
 * Created Date: Monday, August 7th 2017, 1:27:07 pm
 * Author: JX
 * -----
 * Last Modified: Mon Aug 07 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */
#include <iostream>
#include <string>
using namespace std;
class Solution
{
  public:
    string multiply(string num1, string num2)
    {
        int length = num1.length() + num2.length();
        string ans(length, '0');
        for (int i = 0; i < num1.length() / 2; ++i)
        {
            char t = num1[i];
            num1[i] = num1[num1.length() - 1 - i];
            num1[num1.length() - 1 - i] = t;
        }
        for (int i = 0; i < num2.length() / 2; ++i)
        {
            char t = num2[i];
            num2[i] = num2[num2.length() - 1 - i];
            num2[num2.length() - 1 - i] = t;
        }
        


        // 核心代码
        for (int i = 0; i < num2.length(); ++i)
        {
            int t = num2[i] - '0';

            // 进位
            int r = 0;
            for (int j = 0; j < num1.length(); ++j)
            {
                int b = num1[j] - '0';
                
                // 本次积
                int tb = t * b + (ans[i + j] - '0') + r;

                // 进位
                r = tb / 10;
                int n = tb % 10;
                ans[i + j] = n + '0';
            }
            // 最高位进位
            if (r != 0) {
                ans[i+num1.length()] = r + '0';
            }
        }


        for (int i = length - 1; i >= 0; i--)
        {
            if (ans[i] != '0')
            {
                ans = ans.substr(0, i + 1);
                break;
            }
        }
        if (ans[ans.length() - 1] == '0')
        {
            return "0";
        }
        for (int i = 0; i < ans.length()/2; ++i) {
            char t = ans[i];
            ans[i] = ans[ans.length() - 1 - i];
            ans[ans.length() - 1 - i] = t;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std:;cout << s.multiply("9","9");
    return 0;
}
