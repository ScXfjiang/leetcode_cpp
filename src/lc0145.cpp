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
std::vector<int> postorderTraversal(TreeNode* root) {
  static std::vector<int> res = {};
  if (!root) { return res; }
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  res.push_back(root->val);
  return res;
}

// Solution 2: Iterative
std::vector<int> postorderTraversal(TreeNode* root) {
  std::vector<int> res = {};
  if (!root) { return res; }
  std::stack<TreeNode*> stk;
  TreeNode* curr = root;
  TreeNode* last_visit = nullptr;
  while (curr || !stk.empty()) {
    while (curr) {
      stk.push(curr);
      curr = curr->left;
    }
    TreeNode* top = stk.top();
    if (top->right && top->right != last_visit) {
      // right node exists && right node is not visited
      curr = top->right;
    } else {
      // right node does not exist || right node is visited
      // handle the node, e.g., print it
      res.push_back(top->val);
      last_visit = top;
      stk.pop();
    }
  }
  return res;
}
