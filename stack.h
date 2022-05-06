#include<iostream> 
using namespace std;

template <class T>

class Snode
{
   public:
   
    T data;
    Snode*next;
      
    node()
    {
        data = 0;
        next = NULL;
    }
    // node(T  x)
    // {
    //     data = x;
    // }
   

};
template < class T>
class stack 
{
    Snode<T>* top;
    
    public:
    

    stack()
    {
        top = NULL;
    }

    void push(T y)
    {
        Snode<T>* temp = new Snode<T>;

        if(top == NULL)
        {
            temp->data = y;
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

    bool empty()
    {
        if(top == NULL)
        {
            return true;
        }
        return false;
    }
    void pop()
    {
        if(top==NULL)
            return;
  
   else {
      
      top = top->next;
    }
    }
};