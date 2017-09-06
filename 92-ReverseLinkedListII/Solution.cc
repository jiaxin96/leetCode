/**
 * File: e:\code\leetCode\92-ReverseLinkedListII\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, September 5th 2017, 7:31:17 pm
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
*/
 class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m == n) return head;
        ListNode * l = head;
        for (int i = 0; i < m-2; ++i) {
            l = l->next;
        }
        ListNode* pre = NULL;
        ListNode* cur = (m ==1 ? l : l->next);
        ListNode* revTile = l->next;
        ListNode* nex = cur->next;

        for (int i = 0; i < n-m && nex; ++i) {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        cur->next = pre;
        l->next = m == 1 ? nex : cur;
        if (m != 1) revTile->next = nex;
        return m == 1 ? cur : head;
    }
};