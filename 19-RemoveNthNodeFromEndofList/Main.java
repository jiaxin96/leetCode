public class Main{
    public static void main(String[] args) {
        
    }
}


//  Definition for singly-linked list.
class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
}
 
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode pos = head;        
        ListNode pre = head;
        for (int i = 0; i < n; ++i) {
            pos = pos.next;
        }
        if (pos == null) {
            head = head.next;
            return head;
        }
        while(pos.next != null) {
            pos = pos.next;
            pre = pre.next;
        }
        pre.next = pre.next.next;
        return head;
    }
}