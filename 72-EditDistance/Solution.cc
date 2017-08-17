/**
 * File: e:\code\leetCode\72-EditDistance\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Thursday, August 17th 2017, 2:06:30 pm
 * Author: JX
 * -----
 * Last Modified: Thu Aug 17 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.length()+1][word2.length()+1] = {{0}};
        for (int i = 0; i <= word1.length(); ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= word2.length(); ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= word1.length(); ++i) {
            for (int j = 1; j <= word2.length(); ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
};