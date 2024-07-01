// Definition of a binary tree node
#include <iostream>
#include <algorithm>
#include <vector>

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

    void printTree(TreeNode *root) {
      if (root != nullptr) {
        std::cout << "node: " << root->val_;
        if (root->left_ != nullptr && root->right_ != nullptr) {
          std::cout << ", left: " << root->left_->val_ << ", right: " << root->right_->val_ << '\n';
        } else {
          std::cout << ", left: empty" << ", right: empty"  << '\n';
        }

        if (root->left_ != nullptr) {
          printTree(root->left_);
        }

        if (root->right_ != nullptr) {
          printTree(root->right_);
        }
      }
    }
};

int main() {

  Solution solution;

  std::vector<int> input{3,9,20,0,0,15,7};

  TreeNode *tree = new TreeNode(input[0]);
  TreeNode *root = tree;

  for (int ii=0; ii<(input.size()-1)/2; ++ii) {
    TreeNode *left  = new TreeNode(input[2*ii+1]);
    TreeNode *right = new TreeNode(input[2*(ii+1)]);

    tree->left_  = left;
    tree->right_ = right;

    if (input[2*ii+1] == 0)   tree->left_ = nullptr;
    if (input[2*(ii+1)] == 0) tree->right_ = nullptr;

    if (tree->left_ == nullptr || tree->right_ == nullptr) {
      tree = root;
    }

    if ((ii+1) % 2 != 0) {
      tree = tree->left_;
    } else {
      tree = tree->right_;
    }
  }

  solution.printTree(root);

  std::cout << '\n';
  std::cout << "Max depth equal to: " << solution.maxDepth(root) << '\n';

  return 0;
}
