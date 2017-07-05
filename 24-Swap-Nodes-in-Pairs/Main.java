/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        return reverse(head);
    }
    private ListNode reverse(ListNode root) {
    	if (root != null && root.next != null) {
    		int t = root.val;
    		root.val = root.next.val;
    		root.next.val = t;
    		reverse(root.next.next);

    	}
    	return root;
    }
}
public class Main {
	public static void main(String[] args) {
		
	}
}
