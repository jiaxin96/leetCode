/**
 * File: e:\code\leetCode\109-ConvertSortedListtoBinarySearchTree\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Friday, September 8th 2017, 8:58:59 pm
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        int l = 0;
        ListNode* it = head;
        while(it) {
            l++;
            it = it->next;
        }
        return buildTree(0, l-1, &head);
    }
    TreeNode* buildTree(int b, int e, ListNode** head) {
        int m = (b+e+1)/2;
        
        if (b > e) return NULL;
        
        TreeNode* left = buildTree(b, m-1, head);
        TreeNode* root = new TreeNode((*head)->val);

        *head = (*head)->next;

        TreeNode* right = buildTree(m+1, e, head);
        root->left = left;
        root->right = right;
        return root;
    }
};