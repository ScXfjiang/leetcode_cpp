#include <iostream>
#include <stack>
#include <queue>

class BTNode {
 public:
  BTNode(int data) : data_(data), left_(nullptr), right_(nullptr) {}

  int data_;
  BTNode* left_;
  BTNode* right_;
};

// Interface
BTNode* BSTInsertRecursive(BTNode* root, int data);
BTNode* BSTInsertIterative(BTNode* root, int data);
void PreorderTraversalRecursive(BTNode* root);
void PreorderTraversalIterative(BTNode* root);
void InorderTraversalRecursive(BTNode* root);
void InorderTraversalIterative(BTNode* root);
void PostorderTraversalRecursive(BTNode* root);
void PostorderTraversalIterativeOneStack(BTNode* root);
void PostorderTraversalIterativeTwoStack(BTNode* root);
void LevelorderTraversal(BTNode* root);

// Implementation
BTNode* BSTInsertRecursive(BTNode* root, int data) {
  if (!root) { return new BTNode(data); }
  if (data < root->data_) {
    root->left_ = BSTInsertRecursive(root->left_, data);
  } else {
    root->right_ = BSTInsertRecursive(root->right_, data);
  }
  return root;
}

BTNode* BSTInsertIterative(BTNode* root, int data) {
  if (!root) { return new BTNode(data); }
  BTNode* prev = nullptr;
  BTNode* curr = root;
  while (curr) {
    prev = curr;
    curr = data < curr->data_ ? curr->left_ : curr->right_;
  }
  if (data < prev->data_) {
    prev->left_ = new BTNode(data);
  } else {
    prev->right_ = new BTNode(data);
  }
  return root;
}

void PreorderTraversalRecursive(BTNode* root) {
  if (!root) { return; }
  // handle the node, e.g., print it
  std::cout << root->data_ << " ";
  PreorderTraversalRecursive(root->left_);
  PreorderTraversalRecursive(root->right_);
}

void PreorderTraversalIterative(BTNode* root) {
  if (!root) { return; }
  std::stack<BTNode*> stk;
  stk.push(root);
  while (!stk.empty()) {
    BTNode* top = stk.top();
    stk.pop();
    // handle the node, e.g., print it
    std::cout << top->data_ << " ";
    if (top->right_) { stk.push(top->right_); }
    if (top->left_) { stk.push(top->left_); }
  }
}

void InorderTraversalRecursive(BTNode* root) {
  if (!root) { return; }
  InorderTraversalRecursive(root->left_);
  // handle the node, e.g., print it
  std::cout << root->data_ << " ";
  InorderTraversalRecursive(root->right_);
}

void InorderTraversalIterative(BTNode* root) {
  if (!root) { return; }
  std::stack<BTNode*> stk;
  BTNode* curr = root;
  while (curr || !stk.empty()) {
    while (curr) {
      stk.push(curr);
      curr = curr->left_;
    }
    BTNode* top = stk.top();
    stk.pop();
    // handle the node, e.g., print it
    std::cout << top->data_ << " ";
    curr = top->right_;
  }
}

void PostorderTraversalRecursive(BTNode* root) {
  if (!root) { return; }
  PostorderTraversalRecursive(root->left_);
  PostorderTraversalRecursive(root->right_);
  // handle the node, e.g., print it
  std::cout << root->data_ << " ";
}

void PostorderTraversalIterativeOneStack(BTNode* root) {
  if (!root) { return; }
  std::stack<BTNode*> stk;
  BTNode* curr = root;
  BTNode* last_visit = nullptr;
  while (curr || !stk.empty()) {
    while (curr) {
      stk.push(curr);
      curr = curr->left_;
    }
    BTNode* top = stk.top();
    if (top->right_ && top->right_ != last_visit) {
      // right node exists && right node is not visited
      curr = top->right_;
    } else {
      // right node does not exist || right node is visited
      // handle the node, e.g., print it
      std::cout << top->data_ << " ";
      last_visit = top;
      stk.pop();
    }
  }
}

// reversed postorder traversal == adjusted preorder traversal
void PostorderTraversalIterativeTwoStack(BTNode* root) {
  if (!root) { return; };
  std::stack<BTNode*> stk1;
  std::stack<BTNode*> stk2;
  BTNode* curr = root;
  stk1.push(curr);
  while (!stk1.empty()) {
    curr = stk1.top();
    stk1.pop();
    stk2.push(curr);
    if (curr->left_) { stk1.push(curr->left_); }
    if (curr->right_) { stk1.push(curr->right_); }
  }
  while (!stk2.empty()) {
    // handle the node, e.g., print it
    std::cout << stk2.top()->data_ << " ";
    stk2.pop();
  }
}

void LevelorderTraversal(BTNode* root) {
  if (!root) { return; }
  std::queue<BTNode*> q;
  q.push(root);
  while (!q.empty()) {
    BTNode* front = q.front();
    q.pop();
    // handle the node, e.g., print it
    std::cout << front->data_ << " ";
    if (front->left_) { q.push(front->left_); }
    if (front->right_) { q.push(front->right_); }
  }
}

int main() {
  // preorder: 5 3 2 4 7 6 8
  // inorder: 2 3 4 5 6 7 8
  // postorder: 2 4 3 6 8 7 5
  // levelorder: 5 3 7 2 4 6 8
  BTNode* root = nullptr;
  root = BSTInsertRecursive(root, 5);
  root = BSTInsertRecursive(root, 3);
  root = BSTInsertRecursive(root, 7);
  root = BSTInsertRecursive(root, 2);
  root = BSTInsertRecursive(root, 4);
  root = BSTInsertRecursive(root, 6);
  root = BSTInsertRecursive(root, 8);
  std::cout << "PreorderTraversalRecursive: " << std::endl;
  PreorderTraversalRecursive(root);
  std::cout << std::endl;
  std::cout << "PreorderTraversalIterative: " << std::endl;
  PreorderTraversalIterative(root);
  std::cout << std::endl;
  std::cout << "InorderTraversalRecursive: " << std::endl;
  InorderTraversalRecursive(root);
  std::cout << std::endl;
  std::cout << "InorderTraversalIterative: " << std::endl;
  InorderTraversalIterative(root);
  std::cout << std::endl;
  std::cout << "PostorderTraversalRecursive: " << std::endl;
  PostorderTraversalRecursive(root);
  std::cout << std::endl;
  std::cout << "PostorderTraversalIterativeOneStack: " << std::endl;
  PostorderTraversalIterativeOneStack(root);
  std::cout << std::endl;
  std::cout << "PostorderTraversalIterativeTwoStack: " << std::endl;
  PostorderTraversalIterativeTwoStack(root);
  std::cout << std::endl;
  std::cout << "LevelorderTraversal: " << std::endl;
  LevelorderTraversal(root);
  std::cout << std::endl;
  return 0;
}