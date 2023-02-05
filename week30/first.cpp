#include <iostream>

struct Node{
  int item;
  Node* link;
};

typedef Node* NodePtr;

void headInsert(NodePtr& head, int data)
{
  NodePtr tmp = new Node;
  tmp->item = data;
  head->next = tmp;
  tmp->next = head->next;
}

auto main() -> int
{
  
  NodePtr head;
  headInsert(head, 4);
  //typedef Node* NodePtr;
  //NodePtr head;
  //head = new Node;
  //head->item = 5; 
  //std::cout<<head->item<<std::endl;
}
