
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
bool isSameTree(TreeNode* p, TreeNode* q) {
  // base case 1: both nodes are children of leaf nodes
  if (!p && !q) { return true; }
  // base case 2: one node is child of leaf node and the other is not
  if (!p || !q) { return false; }
  return (p->val == q->val) && isSameTree(p->left, q->left)
         && isSameTree(p->right, q->right);
}

// Solution 2: Iterative
// p and q are the same tree <==> same preorder/inorder/postorder traversal process
bool isSameTree(TreeNode* p, TreeNode* q) {
  std::stack<TreeNode*> stk_p;
  std::stack<TreeNode*> stk_q;
  stk_p.push(p);
  stk_q.push(q);

  while (!stk_p.empty() && !stk_q.empty()) {
    TreeNode* node_p = stk_p.top();
    stk_p.pop();
    TreeNode* node_q = stk_q.top();
    stk_q.pop();

    if (!node_p && !node_q) { continue; }              // both nodes are null, continue
    if (!node_p || !node_q) { return false; }          // one node is null, not same
    if (node_p->val != node_q->val) { return false; }  // node values differ, not same

    stk_p.push(node_p->right);
    stk_p.push(node_p->left);

    stk_q.push(node_q->right);
    stk_q.push(node_q->left);
  }

  return stk_p.empty() && stk_q.empty();
}