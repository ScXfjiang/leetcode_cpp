struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* dummy_head = new ListNode();
  dummy_head->next = head;
  ListNode* p1 = dummy_head;
  ListNode* p2 = dummy_head;
  for (int i = 0; i <= n; ++i) { p2 = p2->next; }
  while (p2) {
    p2 = p2->next;
    p1 = p1->next;
  }
  ListNode* to_delete = p1->next;
  p1->next = to_delete->next;
  delete to_delete;
  return dummy_head->next;
}
