struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

ListNode* deleteDuplicates(ListNode* head) {
  ListNode* curr = head;
  while (curr && curr->next) {
    if (curr->val == curr->next->val) {
      ListNode* to_delete = curr->next;
      curr->next = to_delete->next;
      delete to_delete;
    } else {
      curr = curr->next;
    }
  }
  return head;
}
