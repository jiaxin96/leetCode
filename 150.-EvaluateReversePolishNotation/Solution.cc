/**
 * File: e:\code\leetCode\150.-EvaluateReversePolishNotation\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Thursday, September 21st 2017, 1:04:44 pm
 * Author: JX
 * -----
 * Last Modified: Thu Sep 21 2017
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
     int evalRPN(vector<string> &tokens)
     {
         stack<int> s;
         int l = tokens.size();
         int a, b, c;
         for (int i = 0; i < l; ++i)
         {
             if (tokens[i].length()>1 || tokens[i][0] >= '0' && tokens[i][0] <= '9')
             {
                 s.push(stoi(tokens[i]));
             }
             else
             {
                 b = s.top();
                 s.pop();
                 a = s.top();
                 s.pop();
                 switch (tokens[i][0])
                 {
                 case '+':
                     c = a + b;
                     break;
                 case '-':
                     c = a - b;
                     break;
                 case '*':
                     c = a * b;
                     break;
                 case '/':
                     c = a / b;
                     break;
                 default:
                     break;
                 }
                 s.push(c);
             }
         }
         return s.top();
     }
 };