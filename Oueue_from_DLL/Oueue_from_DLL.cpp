#include<iostream>
#include<list>          //Oueue_from_DLL.cpp
template< typename T >
class queue{

public:
bool isempty(){
  return dll.empty();
}
void enqueue(T data){
dll.push_back(data);
}
void dequeue(){
if(isempty())  exit(1);
dll.pop_front();   
}
T front(){
if(isempty()) exit(1);    
return dll.front();
}
private:
std::list<T> dll;
};

int main()
{
   queue<int> q;
   q.enqueue(5);
  
  q.dequeue();
   std::cout<<q.front();
   std::cout<<"imwoooooooo";
    return 0;
}