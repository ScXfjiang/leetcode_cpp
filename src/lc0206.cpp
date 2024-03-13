struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

// Solution 1 - Iterative
ListNode* reverseList(ListNode* head) {
  ListNode* prev = nullptr;
  ListNode* curr = head;
  ListNode* next = nullptr;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

// Solution 2 - Iterative
ListNode* reverseList(ListNode* head) {
  ListNode* dummy_head = new ListNode();
  ListNode* curr = head;
  while (curr) {
    ListNode* next = curr->next;
    curr->next = dummy_head->next;
    dummy_head->next = curr;
    curr = next;
  }
  return dummy_head->next;
}

// Solution 3 - Recursive
ListNode* reverseList(ListNode* head) {
  // base case
  if (head == nullptr || head->next == nullptr) { return head; }
  ListNode* rest = reverseList(head->next);
  head->next->next = head;
  head->next = nullptr;
  return rest;
}