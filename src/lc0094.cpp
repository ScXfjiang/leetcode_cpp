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
std::vector<int> inorderTraversal(TreeNode* root) {
  static std::vector<int> res = {};
  if (!root) { return res; }
  inorderTraversal(root->left);
  res.push_back(root->val);
  inorderTraversal(root->right);
  return res;
}

// Solution 2: Iterative
std::vector<int> inorderTraversal(TreeNode* root) {
  std::vector<int> res = {};
  if (!root) { return res; }
  std::stack<TreeNode*> stk;
  TreeNode* curr = root;
  while (curr || !stk.empty()) {
    while (curr) {
      stk.push(curr);
      curr = curr->left;
    }
    TreeNode* top = stk.top();
    stk.pop();
    res.push_back(top->val);
    curr = top->right;
  }
  return res;
}
