#include <unordered_map>

struct TreeNode {
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

  int val;
  TreeNode* left;
  TreeNode* right;
};

// Solution 1 - Iterative
void CreateNode2Parent(TreeNode* root,
                       std::unordered_map<TreeNode*, TreeNode*>& node2parent) {
  if (!root) { return; }
  if (root->left) { node2parent[root->left] = root; }
  if (root->right) { node2parent[root->right] = root; }
  CreateNode2Parent(root->right, node2parent);
  CreateNode2Parent(root->left, node2parent);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) { return nullptr; }
  std::unordered_map<TreeNode*, TreeNode*> node2parent;
  node2parent[root] = nullptr;
  CreateNode2Parent(root, node2parent);
  std::vector<TreeNode*> path_p;
  while (p) {
    path_p.push_back(p);
    p = node2parent[p];
  }
  std::reverse(path_p.begin(), path_p.end());
  std::vector<TreeNode*> path_q;
  while (q) {
    path_q.push_back(q);
    q = node2parent[q];
  }
  std::reverse(path_q.begin(), path_q.end());
  TreeNode* lca = nullptr;
  int i = 0;
  while (i < std::min(path_p.size(), path_q.size()) && path_p[i] == path_q[i]) {
    lca = path_p[i];
    ++i;
  }
  return lca;
}

// Solution 2 - Recursion
// 1. both p and q are in the tree --> LCA
// 2. only one of p and q is in the tree --> that one
// 3. neither p nor q is in the tree --> nullptr
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) { return nullptr; }
  if (root == p || root == q) { return root; }
  // search for LCA in left and right subtrees
  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);
  // if p and q are in different subtrees, return root
  if (left && right) { return root; }
  // o.w., return subtree that contains p or q
  return left ? left : right;
}