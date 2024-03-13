#include <vector>
#include <stack>
struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

// Solution 1: Recursive
std::vector<int> preorderTraversal(TreeNode* root) {
  static std::vector<int> res = {};
  if (!root) { return res; }
  res.push_back(root->val);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
  return res;
}

// Solution 2: Iterative
std::vector<int> preorderTraversal(TreeNode* root) {
  std::vector<int> res = {};
  if (!root) { return res; }
  std::stack<TreeNode*> stk;
  stk.push(root);
  while (!stk.empty()) {
    TreeNode* top = stk.top();
    stk.pop();
    res.push_back(top->val);
    if (top->right) { stk.push(top->right); }
    if (top->left) { stk.push(top->left); }
  }
  return res;
}
