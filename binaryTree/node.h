#ifndef NODE_H
#define NODE_H

template<typename T>
struct node {
  T key_value;
  node *left;
  node *right;
};

#endif
