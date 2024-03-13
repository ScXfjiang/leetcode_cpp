struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

ListNode* rotateRight(ListNode* head, int k) {
  if (head == nullptr || k == 0) { return head; }
  // determine len of linked list
  ListNode* curr = head;
  int len = 1;
  while (curr->next) {
    ++len;
    curr = curr->next;
  }
  // connect tail to head
  curr->next = head;
  // find new tail
  int steps_to_new_tail = len - k % len;
  while (steps_to_new_tail--) { curr = curr->next; }
  // break circle
  head = curr->next;
  curr->next = nullptr;
  return head;
}
