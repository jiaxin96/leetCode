/**
 * File: e:\code\leetCode\112-PathSum\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Friday, September 8th 2017, 10:08:28 pm
 * Author: JX
 * -----
 * Last Modified: Fri Sep 08 2017
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

 
//  效率非常低
 class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int curSum = 0;
        if (root == NULL) return false;
        return helper(root, sum, curSum);
    }
    bool helper(TreeNode* root, int target, int curSum) {
        if (!root) {
            return false;
        }
        bool l = false, r = false;
        if (root->left) l = helper(root->left, target, curSum+root->val);
        if (root->right) r = helper(root->right, target, curSum+root->val);
        
        if (!root->left && !root->right) return curSum+root->val == target;
        
        return l || r;
    }
};