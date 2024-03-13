#include <algorithm>
#include <stk>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

// Solution 1 - Inorder Traversal (Recursive)
bool isValidBST(TreeNode* root) {
  long prev_val = LONG_MIN;
  return InorderCheck(root, prev_val);
}

bool InorderCheck(TreeNode* node, long& prev_val) {
  if (!node) { return true; }
  if (!InorderCheck(node->left, prev_val)) { return false; }
  if (node->val <= prev_val) { return false; }
  prev_val = node->val;
  return InorderCheck(node->right, prev_val);
}

// Solution 2 - Inorder Traversal (Iterative)
bool isValidBST(TreeNode* root) {
  if (!root) { return true; }
  std::stack<TreeNode*> stk;
  long prev_val = LONG_MIN;
  TreeNode* curr = root;
  while (curr || !stk.empty()) {
    while (curr) {
      stk.push(curr);
      curr = curr->left;
    }
    TreeNode* top = stk.top();
    stk.pop();
    if (top->val <= prev_val) { return false; }
    prev_val = top->val;
    curr = top->right;
  }
  return true;
}

// Solution 3 - Value Range Check
bool isValidBST(TreeNode* root) { return validateBST(root, LONG_MIN, LONG_MAX); }

bool validateBST(TreeNode* node, long min_val, long max_val) {
  if (!node) { return true; }
  if (node->val <= min_val || node->val >= max_val) { return false; }
  return validateBST(node->left, min_val, node->val)
         && validateBST(node->right, node->val, max_val);
}
