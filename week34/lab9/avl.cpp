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

Node *left_rotate(Node *x)
{
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
                  height(x->right)) + 1;
  y->height = max(height(y->left),
                  height(y->right)) + 1;
  return y;
}

Node *right_rotate(Node *x){
  Node * y = x->left;
  Node *T2 = y->right;
  y->right = x;
  x->left = T2;
  x->height = max(height(x->left),
                  height(x->right)) + 1;
  y->height = max(height(y->left),
                  height(y->right)) + 1;
  return y;
}

int get_balance(Node *x){
  int x1,x2;
  if(x==nullptr){
    return 0;
  }else{
    if(x->right==nullptr){
      x1=0;
    }else{
      x1=x->right->height;
    }
    if(x->left==nullptr){
      x2=0;
    }else{
      x2=x->left->height;
    }
    return x2-x1;
  }
}
void printInOrder(Node* root){
  if(root!=nullptr){
    printInOrder(root->left);
    std::cout<<(root->key)<<"\n";
    printInOrder(root->right);
  }
}

Node* insert(Node* root,int key){

  if(root==nullptr){
    return new_node(key);
  }
  if(key<root->key){
    root->left = insert(root->left,key);
  }else if (key > root->key){
    root->right = insert(root->right,key);
  }else
    return root;
  root->height = 1 + max(height(root->left),height(root->right));
  return root;

  root->height = height(root);

  int balance = get_balance(root);

  
  if (balance > 1 && key < root->left->key)
    return right_rotate(root);
  
  if (balance < -1 && key > root->right->key)
    return left_rotate(root);
  
  if (balance > 1 && key > root->left->key)
    {
      root->left = left_rotate(root->left);
      return right_rotate(root);
    }
  
  if (balance < -1 && key < root->right->key)
    {
      root->right = right_rotate(root->right);
      return left_rotate(root);
    }
}
