#include <algorithm>
#include <stack>
#include <limits>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

// Solution 1 - Inorder Traversal (Recursive)
int getMinimumDifference(TreeNode* root) {
  int min_diff = std::numeric_limits<int>::max();
  TreeNode* prev = nullptr;
  InorderTraverse(root, prev, min_diff);
  return min_diff;
}

void InorderTraverse(TreeNode* node, TreeNode*& prev, int& min_diff) {
  if (!node) { return; }
  InorderTraverse(node->left, prev, min_diff);
  if (prev) { min_diff = std::min(min_diff, node->val - prev->val); }
  prev = node;
  InorderTraverse(node->right, prev, min_diff);
}

// Solution 2 - Inorder Traversal (Iterative)
int getMinimumDifference(TreeNode* root) {
  if (!root) { return -1; }
  std::stack<TreeNode*> stk;
  TreeNode* curr = root;
  TreeNode* prev = nullptr;
  int min_diff = std::numeric_limits<int>::max();
  while (curr || !stk.empty()) {
    while (curr) {
      stk.push(curr);
      curr = curr->left;
    }
    TreeNode* top = stk.top();
    stk.pop();
    if (prev) { min_diff = std::min(min_diff, top->val - prev->val); }
    prev = top;
    curr = top->right;
  }
  return min_diff;
}
