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
  void insert(int x){
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
