#include <stack>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

class BSTIterator {
 public:
  BSTIterator(TreeNode* root) { PushAll(root); }

  /** @return the next smallest number */
  int next() {
    TreeNode* top = stk.top();
    stk.pop();
    PushAll(top->right);
    return top->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !stk.empty(); }

 private:
  void PushAll(TreeNode* node) {
    while (node) {
      stk.push(node);
      node = node->left;
    }
  }

  std::stk<TreeNode*> stk;
};
