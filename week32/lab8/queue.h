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
  int dequeue(){
    int temp;
    if(rear_value==-1){
      return 0;
    }else{
      temp = a[0];
      for(int i=0;i<rear_value;i++){
	a[i]=a[i+1];
	a[rear_value]=0;
	return temp;
      }
      return a[rear_value];
    }
  }
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
