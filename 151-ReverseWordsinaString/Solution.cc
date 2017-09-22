/**
 * File: e:\code\leetCode\151-ReverseWordsinaString\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Thursday, September 21st 2017, 2:45:06 pm
 * Author: JX
 * -----
 * Last Modified: Fri Sep 22 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

 class Solution {
public:
    void reverseWords(string &s) {
        // Reverse string
        reverse(s.begin(), s.end());
        // Reverse every word
        int i = 0, j = 0;
        while(i != s.size()){
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
            while(i < s.size() && s[i] == ' ') i++, j++;
        }
        // Remove extra ' '
        i = 0, j = 0;
        while(j < s.size()) {
            bool new_word = false;
            while(j < s.size() && s[j] == ' ') {
                new_word = true;
                j++;
            }
            if(j == s.size()) break;
            if(new_word && i > 0) s[i++] = ' ';
            s[i++] = s[j++];
        }
        s = s.substr(0, i);
    }
};