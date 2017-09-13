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
    void reorderList(ListNode* head) {
        if (head == NULL || !head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
           slow = slow->next;
           fast = fast->next->next;
        } 
        ListNode* subH = slow->next;
        slow->next = NULL;
        slow = NULL;
        ListNode* pos = subH->next;
        while(pos) {
            subH->next = slow;
            slow = subH;
            subH = pos;
            pos  = pos->next;
        }
        subH->next = slow;
        slow = head;
        ListNode * tem1, * tem2;
        while(slow && subH) {
            tem1 = slow->next;
            tem2 = subH->next;
            
            slow->next = subH;
            subH->next = tem1;
            
            subH = tem2;
            slow = tem1;
        }
    }
};
