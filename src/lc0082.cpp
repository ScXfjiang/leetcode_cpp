struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

ListNode* deleteDuplicates(ListNode* head) {
  ListNode* dummy_head = new ListNode();
  dummy_head->next = head;
  ListNode* prev = dummy_head;
  while (head != nullptr) {
    if (head->next == nullptr || head->val != head->next->val) {
      prev->next = head;
      prev = prev->next;
      head = head->next;
    } else {
      int duplicateVal = head->val;
      while (head != nullptr && head->val == duplicateVal) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
      }
    }
  }
  prev->next = nullptr;
  return dummy_head->next;
}
