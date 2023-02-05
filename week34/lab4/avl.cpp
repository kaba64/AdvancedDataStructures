#include <iostream>

class Node
{
public:
  int key;
  Node *left;
  Node *right;
  int height;
};

Node* new_node(int key)
{
  Node* node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return(node);
}
