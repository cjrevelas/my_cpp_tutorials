// Definition of a binary tree node
#include <algorithm>

struct TreeNode {
  int val_;
  TreeNode *left_;
  TreeNode *right_;
  TreeNode() : val_(0), left_(nullptr), right_(nullptr) {}
  TreeNode(int val) : val_(val), left_(nullptr), right_(nullptr) {}
  TreeNode(int val, TreeNode *left, TreeNode *right) : val_(val), left_(left), right_(right) {}
};

class Solution {
  public:
    int maxDepth(TreeNode *root) {
      if (root == nullptr) return 0;

      int depth_left  = maxDepth(root->left_);
      int depth_right = maxDepth(root->right_);

      return std::max(depth_left, depth_right) + 1;
    }
};

int main() {

  Solution solution;

  return 0;
}
