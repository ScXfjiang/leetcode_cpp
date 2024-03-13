#include <unordered_set>

struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

// Solution 1 - Tortoise and Hare algorithm
bool hasCycle(ListNode* head) {
  if (!head) { return false; }
  ListNode* slow = head;
  ListNode* fast = head->next;
  while (fast && fast->next) {
    if (slow == fast) { return true; }
    slow = slow->next;
    fast = fast->next->next;
  }
  return false;
}

// Solution 2 - Hash Set
bool hasCycle(ListNode* head) {
  std::unordered_set<ListNode*> visited;
  ListNode* curr = head;
  while (curr) {
    if (visited.find(curr) != visited.end()) { return true; }
    visited.insert(curr);
    curr = curr->next;
  }
  return false;
}