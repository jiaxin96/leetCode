/**
 * File: e:\code\leetCode\114-FlattenBinaryTreetoLinkedList\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Sunday, September 10th 2017, 12:24:31 am
 * Author: JX
 * -----
 * Last Modified: Sun Sep 10 2017
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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode * it  = root;
        
        while (it) {
            if (it->left && it->right) {
                TreeNode* newIt = it->left;
                while(newIt->right) {
                    newIt = newIt->right;
                }
                newIt->right = it->right;
                it->right = it->left;
                it->left = NULL;
            }
            if (it->left) {
                it->right = it->left;
                it->left = NULL;
            }
            it = it->right;
        }

        return root;
    }
};