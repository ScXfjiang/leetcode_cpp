#include <unordered_map>

struct Node {
  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }

  int val;
  Node* next;
  Node* random;
};

// Solution 1 - Hash Map
Node* copyRandomList(Node* head) {
  if (!head) { return nullptr; }
  std::unordered_map<Node*, Node*> origin2copy;
  Node* curr = head;
  while (curr) {
    origin2copy[curr] = new Node(curr->val);
    curr = curr->next;
  }
  for (auto& pair : origin2copy) {
    Node* origin = pair.first;
    Node* copy = pair.second;
    if (origin->next) { copy->next = origin2copy[origin->next]; }
    if (origin->random) { copy->random = origin2copy[origin->random]; }
  }
  return origin2copy[head];
}

// Solution 2
Node* copyRandomList(Node* head) {
  if (!head) { return nullptr; }
  Node* curr = head;
  // first pass: make copy of each node and insert it to the original list
  while (curr) {
    Node* copy = new Node(curr->val);
    copy->next = curr->next;
    curr->next = copy;
    curr = copy->next;
  }
  // second pass: assign random pointers for the copy nodes
  curr = head;
  while (curr) {
    if (curr->random) { curr->next->random = curr->random->next; }
    curr = curr->next->next;
  }
  // third pass: extract the copy list
  curr = head;
  Node* dummy_head = new Node(0);
  Node* copy = dummy_head;
  while (curr) {
    Node* next = curr->next;
    copy->next = next;
    curr->next = next->next;
    curr = curr->next;
    copy = copy->next;
  }
  return dummy_head->next;
}
