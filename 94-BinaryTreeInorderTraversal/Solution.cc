/**
 * File: e:\code\leetCode\94-BinaryTreeInorderTraversal\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, August 30th 2017, 11:56:19 pm
 * Author: JX
 * -----
 * Last Modified: Fri Sep 01 2017
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode* p = root;
        while (p || !s.empty()) {
            while (p != NULL) {
                s.push(p);
                p = p->left;
            }
            if (!s.empty()) {
                p = s.top();
                s.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }
};