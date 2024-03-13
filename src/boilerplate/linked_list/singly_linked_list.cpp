struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

// insert y after x, [x -> z] --> [x -> y -> z]
void insert(ListNode* x, ListNode* y) {
  y->next = x->next;
  x->next = y;
}

// delete y after x, [x -> y -> z] --> [x -> z]
void delete_node(ListNode* x, ListNode* y) {
  x->next = y->next;
  delete y;
}

// traverse a linked list
void traverse(ListNode* head) {
  ListNode* curr = head;
  while (curr) {
    // do something
    curr = curr->next;
  }
}

// search for a node
ListNode* find(ListNode* head, bool (*condition)(ListNode*)) {
  ListNode* curr = head;
  while (curr && !condition(curr)) { curr = curr->next; }
  return curr;
}
