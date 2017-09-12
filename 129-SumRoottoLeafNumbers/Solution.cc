/**
 * File: e:\code\leetCode\129-SumRoottoLeafNumbers\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, September 12th 2017, 7:34:47 pm
 * Author: JX
 * -----
 * Last Modified: Tue Sep 12 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        getAns(root, ans, 0);
        return ans;
    }
    void getAns(TreeNode* root, int &ans, int curSum) {
        if (!root) return;
        curSum = curSum*10 + root->val;
        
        if (!root->left && !root->right) ans += curSum;
        getAns(root->left, ans, curSum);
        getAns(root->right, ans, curSum);
    }
};