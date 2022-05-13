#include <iostream>
#include "binTree.h"

int main() {
  // Dynamic tree allocation (heap)
  BinTree<int> *tree = new BinTree<int>;

  tree->insert(10);
  tree->insert(6);
  tree->insert(5);
  tree->insert(8);
  tree->insert(14);
  tree->insert(11);
  tree->insert(18);

  std::cout << "Tree root: " << tree->search(10)->key_value << "\n\n";

  tree->print_tree();
  tree->destroy_tree();

  //static tree allocation (stack)
  //{
  //  BinTree<int> tree;
  //  BinTree<int>* tree_pointer = &tree;
  //  tree_pointer->insert(10);
  //}

  std::cin.get();
  return 0;
}
