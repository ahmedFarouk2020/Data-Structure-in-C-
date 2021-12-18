// Queue_from_Array.cpp
#include<iostream>

template<typename T,T maxsize=100>
class QueueArr{

public:
bool isempty(){
    return front_ == back_;
}
void enqueue(T data){
    if(isfull())  exit(1);
    queue[back_]=data;
    (back_=back_+1) % maxsize;
}
void dequeue(){
    if(isempty())  exit(1);
    (front_=front_+1) % maxsize;
}
T front(){
   if(isempty())  exit(1);
    return queue[front_];
}

private:
T queue[maxsize];
int front_=0;
int back_=0;
bool isfull(){
    return back_+1 % maxsize == front_;
}
};

int main()
{
    QueueArr<int> q;
    q.enqueue(5);
  /*  q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);*/
    q.dequeue();
      std::cout<<q.front()<<'\n';  
    std::cout<<"imWorking";
    return 0;
}