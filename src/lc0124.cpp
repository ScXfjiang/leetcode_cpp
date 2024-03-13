#include <algorithm>
#include <limits>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

int maxPathSum(TreeNode* root) {
  int max_sum = std::numeric_limits<int>::min();
  maxPathDown(root, max_sum);
  return max_sum;
}

// calculate maximum path sum starting from root and update max_sum
int maxPathDown(TreeNode* root, int& max_sum) {
  // base case: child of leaf node
  if (!root) { return 0; }
  // maximum path sum starting from left and right child, set to zero if negative
  int left = std::max(0, maxPathDown(root->left, max_sum));
  int right = std::max(0, maxPathDown(root->right, max_sum));
  // update max_sum
  max_sum = std::max(max_sum, root->val + left + right);
  // return maximum path sum starting from root
  return std::max(left, right) + root->val;
}
