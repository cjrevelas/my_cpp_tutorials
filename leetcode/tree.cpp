// Definition of a binary tree node
struct TreeNode {
  int val_;
  TreeNode *left_;
  TreeNode *right_;
  TreeNode() : val_(0), left_(nullptr), right_(nullptr) {}
  TreeNode(int val) : val_(val), left_(nullptr), right_(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right) : val_(val), left_(left), right_(right) {}
};
