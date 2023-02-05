#include <iostream>

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
  void Insert(int x){
    BST *newptr;
    if(x<=data){
      newptr = new BST(x);
      left = newptr;
    }else{
      newptr = new BST(x);
      right = newptr;
    }
  }
  int nth_node(int n);
};

auto main() ->int
{
  BST node(10);
  node.Insert(20);
  std::cout<<node.left<<"\n";
  std::cout<<node.right->data<<"\n";
}
