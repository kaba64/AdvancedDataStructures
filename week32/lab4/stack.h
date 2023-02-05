#define MAX 1000

class Stack
{
public:
  int top;
  int a[MAX]; // Maximum size of Stack
  Stack() { top = -1; }
  bool push(int x){
    top+=1;
    if(top>MAX-1){
      return false;
    }else{
      a[top]=x;
      return true;
    }
  }
  int pop(){
    int temp;
    if(top==-1){
      return 0;
    }else{
      temp = a[top];
      a[top] = 0;
      top-=1;
      return temp;
    }
  }
  int peek(){
    if(top==-1){
      return 0;
    }else{
      return a[top];
    }
  }
  bool isEmpty(){
    if(top==-1){
      return true;
    }else{
      return false;
    }
  }
};
