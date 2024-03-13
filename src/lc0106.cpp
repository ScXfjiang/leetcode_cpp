#include <vector>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
  std::unordered_map<int, int> in_val2idx;
  for (int i = 0; i < inorder.size(); i++) { in_val2idx[inorder[i]] = i; }
  return buildTreeRecursive(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1,
                            in_val2idx);
}

TreeNode* buildTreeRecursive(std::vector<int>& inorder, int in_start, int in_end,
                             std::vector<int>& postorder, int post_start, int post_end,
                             std::unordered_map<int, int>& in_val2idx) {
  // base case
  if (in_start > in_end || post_start > post_end) { return nullptr; }
  TreeNode* root = new TreeNode(postorder[post_end]);
  int in_root = in_val2idx[root->val];
  int num_left = in_root - in_start;
  root->left = buildTreeRecursive(inorder, in_start, in_root - 1, postorder, post_start,
                                  post_start + num_left - 1, in_val2idx);
  root->right = buildTreeRecursive(inorder, in_root + 1, in_end, postorder, post_start + num_left,
                                   post_end - 1, in_val2idx);
  return root;
}