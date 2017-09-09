/**
 * File: e:\code\leetCode\113-PathSumII\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Saturday, September 9th 2017, 11:18:24 pm
 * Author: JX
 * -----
 * Last Modified: Sat Sep 09 2017
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        if (root == NULL) return ans;

        getAns(root, ans, tmp, sum, 0);
        
        return ans;
    }
    void getAns(TreeNode * root, vector<vector<int>> & ans, vector<int> & tmp, int target, int sum) {
        if (root == NULL) return;
        
        tmp.push_back(root->val);

        sum += root->val;
        
        if (root->left) getAns(root->left, ans, tmp, target, sum);

        if (root->right) getAns(root->right, ans, tmp, target, sum);
        
        if (!root->left && !root->right) {
            if (sum == target) {
                ans.push_back(tmp);
            }
        }
        
        tmp.pop_back();
        
    }
};