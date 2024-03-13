#include <queue>
#include <vector>

struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

// Solution 1 - Merge Sort
ListNode* sortList(ListNode* head) {
  if (!head || !head->next) { return head; }
  ListNode* slow = head;
  ListNode* fast = head;
  ListNode* prev_mid = nullptr;
  while (fast && fast->next) {
    prev_mid = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev_mid->next = nullptr;
  ListNode* l1 = sortList(head);
  ListNode* l2 = sortList(slow);
  return Merge(l1, l2);
}

ListNode* Merge(ListNode* l1, ListNode* l2) {
  ListNode* dummy_head = new ListNode(0);
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
  if (l1) {
    curr->next = l1;
  } else {
    curr->next = l2;
  }
  return dummy_head->next;
}

// Solution 2 - Priority Queue
ListNode* sortList(ListNode* head) {
  if (!head) { return nullptr; }
  auto compare = [](const ListNode* lhs, const ListNode* rhs) {
    return lhs->val > rhs->val;
  };
  std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> min_heap(
      compare);
  while (head) {
    min_heap.push(head);
    head = head->next;
  }
  ListNode* dummy_head = new ListNode();
  ListNode* curr = dummy_head;
  while (!min_heap.empty()) {
    curr->next = min_heap.top();
    min_heap.pop();
    curr = curr->next;
  }
  curr->next = nullptr;
  return dummy_head->next;
}
