#include <stack>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

// Solution 1 - Inorder Traversal (Recursive)
int kthSmallest(TreeNode* root, int k) {
  int count = 0;
  int result = -1;
  InorderTraverse(root, k, count, result);
  return result;
}

void InorderTraverse(TreeNode* node, int k, int& count, int& result) {
  if (!node || count >= k) { return; }
  InorderTraverse(node->left, k, count, result);
  if (++count == k) {
    result = node->val;
    return;
  }
  InorderTraverse(node->right, k, count, result);
}

// Solution 2 - Inorder Traversal (Iterative)
int kthSmallest(TreeNode* root, int k) {
  if (!root) { return -1; }
  std::stack<TreeNode*> stk;
  TreeNode* curr = root;
  int count = 0;
  while (curr || !stk.empty()) {
    while (curr) {
      stk.push(curr);
      curr = curr->left;
    }
    TreeNode* top = stk.top();
    stk.pop();
    if (++count == k) { return top->val; }
    curr = top->right;
  }
  return -1;
}
