#include <iostream>
#include <list>

using namespace std;

template<class T>

class Stack{
  list<T> data;
public:
  void push(T newItem){
    return data.push_front(newItem);
  }
  T pop(){
    return data.pop_front();
  }
  T top() const{
    return *data.begin();
  }
  bool isEmpty() const{
    return data.size()==0;
  }
  int size() const{
    return data.size();
  }
  void clear(){
    data.clear();
  }
  void print()
  {
    for (auto i:data) {
      std::cout << i << std::endl;
    }
  }
  //void print_stack() const{
  //  
  //  data.print();
  //}
};

auto main() -> int
{
  Stack<int> first;
  for(int i =0;i<3;i++){
    first.push(i);
  }
  first.print();
}
