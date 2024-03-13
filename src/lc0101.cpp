#include <queue>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

// Solution 1: Recursive
bool isSymmetric(TreeNode* root) {
  if (!root) { return true; }
  return isSymmetricRecursive(root->left, root->right);
}

bool isSymmetricRecursive(TreeNode* t1, TreeNode* t2) {
  // base case 1: both nodes are children of leaf nodes
  if (!t1 && !t2) { return true; }
  // base case 2: one node is child of leaf node and the other is not
  if (!t1 || !t2) { return false; }
  return t1->val == t2->val && isSymmetricRecursive(t1->left, t2->right)
         && isSymmetricRecursive(t1->right, t2->left);
}

// Solution 2: Iterative
bool isSymmetric(TreeNode* root) {
  if (!root) { return true; }

  std::queue<TreeNode*> q;
  q.push(root->left);
  q.push(root->right);

  while (!q.empty()) {
    TreeNode* a = q.front();
    q.pop();
    TreeNode* b = q.front();
    q.pop();

    if (!a && !b) { continue; }
    if (!a || !b) { return false; }
    if (a->val != b->val) { return false; }

    q.push(a->left);
    q.push(b->right);

    q.push(a->right);
    q.push(b->left);
  }
  return true;
}