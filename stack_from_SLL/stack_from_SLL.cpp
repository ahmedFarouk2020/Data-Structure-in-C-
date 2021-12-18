#include <iostream>  // stack_from_SLL.cpp
#include<forward_list>
template<typename T>
class stack_SLL{
public:
bool isEmpty() const {
   return stack.empty();
}
void push(T data){
    stack.push_front(data);
}
void pop(){
    if(isEmpty()) exit(1);
   stack.pop_front();
}
T front (){
    if(isEmpty()) exit(1);
   return stack.front();
}

private:
std::forward_list<T> stack;
};

int main()
{
    int a=0;
    std::cin>>a;
   stack_SLL<int> s;
   std::cout<<s.isEmpty()<<'\n';
   s.push(5);
   s.pop();
   std::cout<<s.front();
   std::cout<<"im working";
    return 0;
}