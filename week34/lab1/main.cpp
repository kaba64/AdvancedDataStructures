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
  void insert(int);
  int nth_node(int n);
};

auto main() ->int
{
  BST mytree;
  std::cout<<mytree.data<<"\n";
}
