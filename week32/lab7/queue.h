#define MAX 1000

class Queue {
public:
  int rear_value;
  int a[MAX]; // Maximum size of Queue
  Queue() { rear_value = -1; }
  bool enqueue(int x){
    rear_value+=1;
    if(rear_value>MAX-1){
      return false;
    }else{
      a[rear_value] = x;
      return true;
    }
  }
  int dequeue();
  int front(){
    if(rear_value==-1){
      return 0;
    }else{
      return a[0];
    }
  }
  int rear(){
    if(rear_value==-1){
      return 0;
    }else{
      return a[rear_value];
    }
  }
};
