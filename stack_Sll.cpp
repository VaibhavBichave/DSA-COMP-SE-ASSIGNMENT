#include<iostream> 
using namespace std;



template <class T>

class node
{
   public:
   
    T data;
    node*next;
      
    node()
    {
        data = 0;
        next = NULL;
    }
    node(T  x)
    {
        data = x;
    }
   

};
template < class T>
class stack 
{
    node<T>* top;
    
    public:
    

    stack()
    {
        top = NULL;
    }

    void push(T y)
    {
        node<T>* temp = new node<T>(y);

        if(top == NULL)
        {
            temp->next = top;
            top = temp;
        }
        else
        {
            //top->next = temp;
            temp->next = top;
            top = temp;
        }


    }
    T get_top()
    {
        return top->data;
    }
    void pop()
    {
        if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< top->data <<endl;
      top = top->next;
    }
    }
    void display() {
    node<T>* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}

};

int main(){

    stack<char> obj;
    
    obj.pop();
    obj.display();
    obj.push('v');
    obj.push('9');
    obj.display();
    obj.push('d');
    cout << obj.get_top()<<endl;

    
    obj.display();
    obj.pop();
    obj.pop();
    obj.display();
    cout << obj.get_top();

  




    
    return 0;
}