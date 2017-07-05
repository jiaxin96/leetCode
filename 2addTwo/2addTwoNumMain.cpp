#include <iostream>
#include "addTwoNum.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
  Solution ss;
  ListNode *l1;
  ListNode *tl1;
  l1 = new ListNode(9);
  tl1 = l1;
  // l1 = l1->next = new ListNode(4);
  // l1->next = new ListNode(3);


  ListNode *l2;
  ListNode *tl2;
  l2 = new ListNode(1);
  tl2 = l2;
  l2 = l2->next = new ListNode(9);
  l2->next = new ListNode(9);


  ListNode *ans = ss.addTwoNumbers(tl1, tl2);
  while (ans) {
    cout << ans->val << endl;
    ans = ans->next;
  }
  return 0;
}
