/**
 * File: e:\code\leetCode\116-PopulatingNextRightPointersinEachNode\Solutoin.cc
 * Project: e:\code\leetCode
 * Created Date: Sunday, September 10th 2017, 10:57:55 pm
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
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        queue<TreeLinkNode *> q;
        if (!root)
            return;
        q.push_back(root);
        int c = 0;
        while (!q.empty())
        {
            c = q.size();
            for (int i = 0; i < c;++i)
            {
                TreeLinkNode *f = q.front();
                q.pop();
                if (i != c-1)
                {
                    TreeLinkNode *subling = q.front();
                    f->next = subling;
                }
                else
                {
                    f->next = NULL;
                }
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
        }
    }
};