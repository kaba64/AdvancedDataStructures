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

auto main() -> int
{
  root = insert(root, 1);  
  root = insert(root, 2);
  if(root->key == 2)
    
  Node *root = insertnb(NULL, 10);
  root = insertnb(root, 20);
  root = insertnb(root, 30);
  root = insertnb(root, 40);
  root = insertnb(root, 50);
  root = insertnb(root, 25);
  printInOrder(root);
  //cout<<get_balance(root)<<"\n";
  //printf("%i",get_balance(root->right->right->right));
  //cout<<"\n";
  //Node *root = insertnb(NULL, 30);
  //root = insertnb(root, 20);
  //root = insertnb(root, 10);
  //root = left_rotate(root);
  //root = right_rotate(root);
  //cout<<root->key<<";"<<root->height<<"\n";
  //cout<<root->left->key<<";"<<root->left->height<<"\n";
  //cout<<root->right->key<<";"<<root->right->height<<"\n";
}
