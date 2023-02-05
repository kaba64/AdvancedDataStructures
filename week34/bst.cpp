#include <iostream>
#include <queue>

template <class T>
class BSTNode{
  T data;
  BSTNode<T>* parent;
  BSTNode<T>* left;
  BSTNode<T>* right;
public:
  BSTNode(T newdata=t(),BSTNode<T>* newParent=nullptr,BSTNode<T>* newLeft=nullptr,BSTNode<T>* newRight=nullptr):
    data(newdata), parent(newParent), left(newLeft), right(newRight){}
  friend calss BST<T>;
  int getSize() const;
};

template <class T>
int BSTNode<T>::getSize() const{
  int count = 1;
  if(left!=nullptr)
    count += left->getSize();
  if(right!nullptr)
    count += left->getSize();
  return count;
}

template <class T>
void BST<T>::printInOrder(BSTNode<T>* node){
  if(node!=nullptr){
    printInOrder(node->left);
    std::cout<<node->data<<",";
    printInOrder(node->right);
  }
}

template <class T>
void BST<T>::printPreOrder(BSTNode<T>* node){
  if(node!=nullptr){
    std::cout<<node->data<<",";
    printPreOrder(node->left);
    printPreOrder(node->right);
  }
}
template <class T>
void BST<T>::printPostOrder(BSTNode<T>* node){
  if(node!=nullptr){
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout<<node->data<<",";
  }
}

template <class T>
void BST<T>::printLevelOrder(){
  queue<BSTNode<T>*> q;
  q.push(root);
  while(!q.empty()){
    BSTNode<T>* temp=q.front();
    q.pop();
    std::cout<<temp->data<<",";
    if(temp->left!=nullptr)
      q.push(temp->left);
    if(temp->right!=nullptr)
      q.push(temp->right);
  }
}
