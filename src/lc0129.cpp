struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

int sumNumbers(TreeNode* root) { return sumNumbersRecursive(root, 0); }

int sumNumbersRecursive(TreeNode* node, int cur_sum) {
  // base case 1: child of leaf node
  if (!node) { return 0; }
  cur_sum = cur_sum * 10 + node->val;
  // base case 2: leaf node
  if (!node->left && !node->right) { return cur_sum; }
  return sumNumbersRecursive(node->left, cur_sum) + sumNumbersRecursive(node->right, cur_sum);
}