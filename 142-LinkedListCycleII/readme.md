# LeetCode 143. Reorder List 刷题笔记
---
**描述**
>Given a singly linked list L: L0?L1?…?Ln-1?Ln,
 reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…
 You must do this in-place without altering the nodes' values.

>For example,Given {1,2,3,4}, reorder it to {1,4,2,3}.

---
**分析**
题目要求我们把一个链表按照从头到尾,从尾到头分别每次取一个值交叉的排列成新的链表.
最直接的想法就是从中间分开链表,然后两头开始把后面的节点插入前半段链表.
但是由于是单链表,就算遍历得到最后的位置也不能向前迭代,所以要有一个把后半段链表翻转的过程,
于是得到如下思路:
<ol>
<li>使用快慢指针法将链表分开为2部分</li>
<li>后半段翻转</li>
<li>2段合并</li>
</ol>

##### 注:
快慢指针法:
使用两个指针slow和fast初始化都为链表头节点,
但是每次fast的步长为2即 fast = fast->next->next;
这样fast的速度为slow的2倍,当fast到了终点的时候slow在链表中部.
快慢指针可以解决多种链表问题,如判断链表是否有环路,有的话快慢指针一定会相遇,等等
---

**AC代码**
```c
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
```