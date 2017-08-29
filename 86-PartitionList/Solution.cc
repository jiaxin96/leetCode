/**
 * File: e:\code\leetCode\86-PartitionList\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Monday, August 28th 2017, 11:32:49 am
 * Author: JX
 * -----
 * Last Modified: Tue Aug 29 2017
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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) return head;
        // small
        ListNode* sH = new ListNode(0);
        ListNode* tsH = sH;
        // big
        ListNode* bH = new ListNode(0);
        ListNode* tbH = bH;
        while(head != NULL) {
            if (head->val < x) {
                tsH->next = head;
                tsH = tsH->next;
            } else {
                tbH->next = head;
                tbH = tbH->next;
            }
            head = head->next;
        }
        tbH->next = NULL;
        tsH->next = bH->next;
        return sH->next;
    }
};