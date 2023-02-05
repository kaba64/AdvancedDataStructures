#include <iostream>
#include <vector>

class BST
{
public:
  int data;
  BST *left, *right;
  BST(){
    data=0;
    left=nullptr;
    right=nullptr;
  }
  BST(int x)
  {
    data=x;
    left=nullptr;
    right=nullptr;
  }
  BST *root=this;
  void Insert(int x){
    InsertHelper(&root,x);
  }
  void InsertHelper(BST **root,const int x){
    if(*root==nullptr){
      *root = new BST(x);
    }else{
      if(x<=(*root)->data){
	InsertHelper(&((*root)->left),x);
      }else{
	InsertHelper(&((*root)->right),x);
      }
    }
  }
  int nth_node(int n){
    std::vector<int> d;
    printInOrder(root,d);
    return d[n-1];
  }
  void printInOrder(BST* root,std::vector<int>& d){
    if(root!=nullptr){
      printInOrder(root->left,d);
      d.push_back(root->data);
      printInOrder(root->right,d);
    }
  }
};

auto main() ->int
{
  BST node(10);
  node.Insert(20);
  node.Insert(30);
  node.Insert(1);
  node.Insert(2);
  int i = node.nth_node(3);
  std::cout<<i<<"\n";
  //std::cout<<((node.left)->right)->data<<"\n";
  //std::cout<<(node.right)->data<<"\n";
}
