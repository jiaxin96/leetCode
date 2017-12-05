/**
 * File: e:\code\leetCode\299-BullsandCows\Solution.cc
 * Project: e:
 * Created Date: Friday, December 1st 2017, 11:56:53 pm
 * Author: JX
 * -----
 * Last Modified: Sat Dec 02 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution
{
  public:
    string getHint(string secret, string guess)
    {
        vector<int> dit(10,0);
        int A = 0, B = 0;
        for (int i = 0; i < secret.length(); ++i) {
            dit[secret[i]-'0']++;
            if (guess[i] == secret[i]) {
                B++;
                dit[guess[i]-'0']--;
            }
        }
        for (int i = 0; i < guess.length(); ++i) {
            if (guess[i] == secret[i]) {
                continue;
            } else if (dit[guess[i]-'0'] >= 1) {
                dit[guess[i]-'0']--;
                A++;
            }
        }
        return to_string(B)+"A"+to_string(A)+"B";
    }
};