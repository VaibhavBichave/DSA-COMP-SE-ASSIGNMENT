#include<iostream> 
using namespace std;

template <class T>
class queue;

template <class T>
class node
{
     T data;
    node*next;
      
   public:
   
   
    node()
    {
        data = 0;
        next = NULL;
    }
    node(T x)
    {
        data = x;
    }
    friend queue<T>;
    


};
template <class T>
class queue

{
    node<T>* start;
    node<T>* end;
    public:

    queue()
    {
        start = end = NULL;

    }

    bool empty()
    {
        if(start == NULL)
        {
            return true;
        }
        return false;
    }
    void push(T y)
    {
        node<T>* temp = new node<T>(y);
        if(start == NULL)
        {
            temp->next = NULL;
            start = end = temp;  
        }
        else
        {
            temp->next = NULL;
            end->next = temp;
            end = temp;


        }

    }
    T get_front()
    {
        return start->data;
    }
       void pop()
        {
            if(start==NULL)
                cout<<"Queue  Underflow"<<endl;
            else
            {
                //cout<<"The popped element is "<< start->data <<endl;
              // node<T>* temp = start;
                start = start->next;
                //  return start;

            }
          
            
        }
        void display() {
        node<T>* ptr;
    if(start==NULL)
    cout<<"Queue is empty";
    else {
        ptr = start;
      cout<<"Queue elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}

};
