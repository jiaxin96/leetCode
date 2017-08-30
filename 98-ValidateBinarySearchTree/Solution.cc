/**
 * File: e:\code\leetCode\98-ValidateBinarySearchTree\S.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, August 30th 2017, 12:27:08 am
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        // 向右下界变
        // 向左上界变
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};