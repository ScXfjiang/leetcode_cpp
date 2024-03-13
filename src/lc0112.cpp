struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

bool hasPathSum(TreeNode* root, int targetSum) {
  // base case 1: child of leaf node
  if (!root) { return false; }
  // base case 2: leaf node
  if (!root->left && !root->right) { return root->val == targetSum; }
  return hasPathSum(root->left, targetSum - root->val)
         || hasPathSum(root->right, targetSum - root->val);
}