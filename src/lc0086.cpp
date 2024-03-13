struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

ListNode* partition(ListNode* head, int x) {
  ListNode* less_dummy_head = new ListNode();
  ListNode* greater_dummy_head = new ListNode();
  ListNode* less_ptr = less_dummy_head;
  ListNode* greater_ptr = greater_dummy_head;
  while (head) {
    if (head->val < x) {
      less_ptr->next = head;
      less_ptr = less_ptr->next;
    } else {
      greater_ptr->next = head;
      greater_ptr = greater_ptr->next;
    }
    head = head->next;
  }
  less_ptr->next = greater_dummy_head->next;
  greater_ptr->next = nullptr;
  return less_dummy_head->next;
}
