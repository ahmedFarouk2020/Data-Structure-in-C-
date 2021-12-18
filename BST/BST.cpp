#include<iostream>

template<typename T>
class BST{
private:
  struct node{
    node* right;
    node* left;
    T data;

    node(T value ){
      right=nullptr;
      left=nullptr;
      data=value;
    }
  };
node* root=nullptr;
public:

void add_member(T value){
    if(root==nullptr)
     root = new node(value); 
     std::cout<<value<<' ';
      return;
    node* temp=root;
    node* parent;
    while(temp!=nullptr)
    {
    node* parent=temp;
    if(value >= temp->data )
    {
        temp=temp->right;
    }  
    else 
    {temp=temp->left;}
    }
   if(value >= parent->data) parent->right=new node(value);
 else  parent->left =new node(value);
 std::cout<<value<<' ';
}
/*void search(T data){

}*/


};

int main()
{
   BST<int> bst;
   bst.add_member(5);
    return 0;
}