#include <vector>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
  std::unordered_map<int, int> in_val2idx;
  for (int i = 0; i < inorder.size(); i++) { in_val2idx[inorder[i]] = i; }
  return buildTreeRecursive(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1,
                            in_val2idx);
}

TreeNode* buildTreeRecursive(std::vector<int>& preorder, int pre_start, int pre_end,
                             std::vector<int>& inorder, int in_start, int in_end,
                             std::unordered_map<int, int>& in_val2idx) {
  // base case
  if (pre_start > pre_end || in_start > in_end) { return nullptr; }
  TreeNode* root = new TreeNode(preorder[pre_start]);
  int in_root = in_val2idx[root->val];
  int num_left = in_root - in_start;
  root->left = buildTreeRecursive(preorder, pre_start + 1, pre_start + num_left, inorder, in_start,
                                  in_root - 1, in_val2idx);
  root->right = buildTreeRecursive(preorder, pre_start + num_left + 1, pre_end, inorder,
                                   in_root + 1, in_end, in_val2idx);

  return root;
}
