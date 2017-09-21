/**
 * File: e:\code\leetCode\147-InsertionSortList\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Thursday, September 21st 2017, 10:20:06 am
 * Author: JX
 * -----
 * Last Modified: Thu Sep 21 2017
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        auto itPre = head, itPos = head;
        ListNode* tmp = head;
        while(itPre->next != NULL) {
            
            itPos = itPre->next;
            tmp = itPre;
            while (itPos != NULL) {
                if (itPos->val < tmp->val) tmp = itPos;
                itPos = itPos->next;
            }

            if (tmp != itPre) {
                int tt = tmp->val;
                tmp->val = itPre->val;
                itPre->val = tt; 
            }

            itPre = itPre->next;
        }

        return head;

        
    }
};