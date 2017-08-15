/**
 * File: e:\code\leetCode\61-RotateList\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Tuesday, August 15th 2017, 3:15:04 pm
 * Author: JX
 * -----
 * Last Modified: Wed Aug 16 2017
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tp = head;
        int l = 0;
        while(tp != NULL) {
            tp = tp->next;
            l++;
        }
        if (head == NULL || k % l == 0) return head;
        k = k % l;
        ListNode* pos = head;
        ListNode* pre = head;
        for (int i = 0; i < k; ++i) {
            pos = pos->next;
        }
        if (pos == NULL) {
            return head;
        }
        while (pos->next != NULL) {
            pos = pos->next;
            pre = pre->next;
        }

        ListNode* newH = pre->next;
        pre->next = NULL;

        pos->next = head;
        head = newH;

        return head;
        
    }
};