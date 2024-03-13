struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

// Solution 1 - iterative
ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (!head || left == right) { return head; }
  ListNode* dummy_head = new ListNode();
  dummy_head->next = head;
  ListNode* prev = dummy_head;
  // move prev to the node just before the left node
  for (int i = 0; i < left - 1; ++i) { prev = prev->next; }
  // reverse the sublist from left to right
  ListNode* curr = prev->next;
  ListNode* next = nullptr;
  for (int i = 0; i < right - left; ++i) {
    next = curr->next;
    curr->next = next->next;
    next->next = prev->next;
    prev->next = next;
  }
  return dummy_head->next;
}

// Solution 2 - iterative
ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (!head || left == right) { return head; }
  ListNode* dummy_head = new ListNode();
  dummy_head->next = head;
  ListNode* prev = dummy_head;
  // move prev to the node before the left position
  for (int i = 0; i < left - 1; ++i) prev = prev->next;
  // iteratively insert the node to the front of the reversed sublist
  ListNode* start = prev->next;
  ListNode* then = start->next;
  for (int i = 0; i < right - left; ++i) {
    start->next = then->next;
    then->next = prev->next;
    prev->next = then;
    then = start->next;
  }
  return dummy_head->next;
}
