
#include <algorithm>
#include <limits>

struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

// Solution 1 - Iterative
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode* dummy_head = new ListNode();
  ListNode* curr = dummy_head;
  while (l1 || l2) {
    int val1 = l1 ? l1->val : std::numeric_limits<int>::max();
    int val2 = l2 ? l2->val : std::numeric_limits<int>::max();
    if (val1 < val2) {
      curr->next = new ListNode(l1->val);
      curr = curr->next;
      l1 = l1->next;
    } else {
      curr->next = new ListNode(l2->val);
      curr = curr->next;
      l2 = l2->next;
    }
  }
  return dummy_head->next;
}

// Solution 2 - Iterative
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode* dummy_head = new ListNode();
  ListNode* curr = dummy_head;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      curr->next = l1;
      l1 = l1->next;
    } else {
      curr->next = l2;
      l2 = l2->next;
    }
    curr = curr->next;
  }
  curr->next = l1 ? l1 : l2;
  return dummy_head->next;
}

// Solution 3 - Recursion
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  // base cases
  if (!l1) { return l2; }
  if (!l2) { return l1; }
  if (l1->val < l2->val) {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  } else {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
}