#include <iostream>
using namespace std;

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
int height(Node *nodein)
{
  if (nodein == NULL)
    return 0;
  return nodein->height;
}

Node* insertnb(Node* root,int key){

  if(root==nullptr){
    return new_node(key);
  }
  if(key<root->key){
    root->left = insertnb(root->left,key);
  }else if (key > root->key){
    root->right = insertnb(root->right,key);
  }else
    return root;
  root->height = 1 + max(height(root->left),height(root->right));
  return root;
}
