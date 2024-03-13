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
void flatten(TreeNode* root) {
  // base case
  if (!root) { return; }
  flatten(root->left);
  flatten(root->right);
  // temporarily store the right child as it will be overwritten.
  TreeNode* temp_right = root->right;
  if (root->left) {
    // attach the left subtree to the right of the root
    root->right = root->left;
    root->left = nullptr;
    // attach the original right subtree to the tail of the new right subtree
    TreeNode* curr = root->right;
    while (curr->right) { curr = curr->right; }
    curr->right = temp_right;
  }
}

// Solution 2: Iterative
void flatten(TreeNode* root) {
  TreeNode* curr = root;
  while (curr) {
    if (curr->left) {
      // find the rightmost node of the left subtree
      TreeNode* predecessor = curr->left;
      while (predecessor->right) { predecessor = predecessor->right; }
      // make the curr node's right child the right child of its predecessor
      predecessor->right = curr->right;
      // move the left child to the right and set the left child to nullptr
      curr->right = curr->left;
      curr->left = nullptr;
    }
    // move to the right child, which is now the original left child or the old right child
    curr = curr->right;
  }
}
