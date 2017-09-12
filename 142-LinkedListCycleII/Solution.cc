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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode * slow = head, * fast = head;
        bool hasCircle = false;
        while (fast != NULL && fast->next != NULL) {
             fast = fast->next->next;
             slow = slow->next;
             if(slow == fast) {
                 hasCircle = true;
                 break;
             }
        }
        if (hasCircle == false) {
             return NULL;
        }
        ListNode* h = head;
        while(h != slow) {
            slow = slow->next;
            h = h->next;
        }
        return h;
        
    }
};
