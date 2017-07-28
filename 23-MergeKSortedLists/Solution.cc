/**
 * File: e:\code\leetCode\23-MergeKSortedLists\Solution.cc
 * Project: e:\code\leetCode
 * Created Date: Monday, July 24th 2017, 3:43:09 pm
 * Author: JX
 * -----
 * Last Modified: Mon Jul 24 2017
 * Modified By: JX
 * -----
 * Copyright (c) 2017 SYSU-SDCS-RJX
 * 
 * 学习使用
 * github地址:https://github.com/jiaxin96
 */





class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(0);
        ListNode* nxtptr=head;
        while(1){
            ListNode ** temp=nullptr;
            int smallest=INT_MAX;
            bool end=true;
            for(auto& x: lists){
                if(x){
                    end=false;
                    if(x->val<smallest){
                        temp=&x;
                        smallest=x->val;
                    }
                }
            }
                 if(end) break;
                nxtptr->next=*temp;
                nxtptr=nxtptr->next;
                (*temp)=(*temp)->next;
        }
        return head->next;
    }
};