/**
 * File: e:\code\leetCode\102-BinaryTreeLevelOrderTraversal\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Wednesday, September 6th 2017, 1:25:11 pm
 * Author: JX
 * -----
 * Last Modified: Wed Sep 06 2017
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> tmp;
        q.push(root);
        int rowCount;
        while (!q.empty()) {
            rowCount = q.size();
            for (int i = 0; i < rowCount; ++i) {
                TreeNode * f =q.front();
                q.pop();
                tmp.push_back(f->val);
                if (f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};