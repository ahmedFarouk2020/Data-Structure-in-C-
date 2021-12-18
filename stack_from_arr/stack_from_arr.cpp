#include <iostream>  // stack_from_arr.cpp

template<typename T,T maxsize=500>
class stack_Arr{
    public:
    bool isEmpty()const {
    return top ==-1;
    }

    void push(T data) {
    if(isFull())    exit(1);
    stack_[++top]=data;
    }

    void pop() {
    if(isEmpty()); exit(1);
    top--;
    };
    T front () const
    {
    if(isEmpty()) return 0; 
    return stack_[top];
    }

private:
T stack_[maxsize] ;
int top=-1;
bool isFull()const {return (top+1) == maxsize;}
};

int main()
{
    stack_Arr<int,4> s;
std::cout<<s.isEmpty() <<'\n'; 
 std::cout<<"i am working" ;
    return 0;
}