/*
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) ===>342+456 = 708
Output: 7 -> 0 -> 8
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <string>
 #include <iostream>
 #include <sstream>
 using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // cout << l1->val << "@@@" << endl;
      // cout << l2->val << l2->next->val << l2->next->next->val << "@@@" << endl;


      ListNode * answer;
      string strl1 = "";
      string strl2 = "";
      while (l1) {
        int temp = l1->val;
        string tempstr = "";
        stringstream ss;
        ss << temp;
        ss >> tempstr;
        strl1 += tempstr;
        l1 = l1->next;
      }

      while (l2) {
        int temp = l2->val;
        string tempstr = "";
        stringstream ss;
        ss << temp;
        ss >> tempstr;
        strl2 += tempstr;
        l2 = l2->next;
      }

      // cout << strl1 << "@@@" << endl;
      // cout << strl2 << "@@@" << endl;

      int maxl = (strl1.length() > strl2.length() ? strl1.length() : strl2.length());
      strl1.resize(maxl, '0');
      strl2.resize(maxl, '0');

      string ans = "";
      int tile = 0;
      int top = 0;
      for (size_t i = 0; i < maxl; i++) {
        int temp = (strl1[i] - '0') + (strl2[i] - '0') + top;
        top = temp / 10;
        tile = temp % 10;

        string tempstr = "";
        stringstream ss;
        ss << tile;
        ss >> tempstr;
        ans += tempstr;
      }
      if (top) {
        string tempstr = "";
        stringstream ss;
        ss << top;
        ss >> tempstr;
        ans += tempstr;
      }

      int car = 0;
      ListNode *temp;
      for (int i = 0; i < ans.length(); ++i) {
        if (car == 0) {
          temp = new ListNode(ans[i] - '0');
          answer = temp;
        } else {
          temp->next = new ListNode(ans[i] - '0');
          temp = temp->next;
        }
        car++;
      }


      // ListNode *tt = answer;
      // cout << tt->val << tt->next->val << "@@@" << endl;

      // cout << car << endl;
      return answer;
    }


};
