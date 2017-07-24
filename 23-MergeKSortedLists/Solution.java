import java.util.List;

/**
 * File: e:\code\leetCode\23-MergeKSortedLists\Solution.java
 * Project: e:\code\leetCode
 * Created Date: Monday, July 24th 2017, 1:49:40 pm
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

//   Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;

    }
}

public class Solution {
    public static ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0)
            return null;
        ListNode head = new ListNode(0);
        ListNode nextNode = head;
        boolean end = false;

        while (true) {
            ListNode temp = null;
            end = true;
            int minVal = Integer.MAX_VALUE;
            int minINdex = 0;
            for (int i = 0; i < lists.length; ++i) {
                if (lists[i] != null) {
                    end = false;
                    if (lists[i].val <= minVal) {
                        minVal = lists[i].val;
                        temp = lists[i];
                        minINdex = i;
                    }
                }
            }
            if (end == true)
                break;
            nextNode.next = temp;
            nextNode = nextNode.next;
            lists[minINdex] = lists[minINdex].next;
        }
        return head.next;
    }
    public static void main(String[] args) {
        ListNode h = new ListNode(0);
        h.next = new ListNode(2);
        ListNode[] a = new ListNode[1];
        a[0] = h;
        mergeKLists(a);
    }
}