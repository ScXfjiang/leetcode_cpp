struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

int countNodes(TreeNode* root) {
  if (!root) { return 0; }
  int left_h = 0;
  int right_h = 0;
  TreeNode* left = root;
  TreeNode* right = root;
  while (left) {
    ++left_h;
    left = left->left;
  }
  while (right) {
    ++right_h;
    right = right->right;
  }
  // base case: full binary tree
  if (left_h == right_h) { return (1 << left_h) - 1; }
  // non-full complete binary tree
  return 1 + countNodes(root->left) + countNodes(root->right);
}
