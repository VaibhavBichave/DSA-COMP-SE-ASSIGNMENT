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
    
        void pop()
        {
            if(start==NULL)
                cout<<"Queue  Underflow"<<endl;
            else
            {
                cout<<"The popped element is "<< start->data <<endl;
                start = start->next;

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

int main(){
    queue<char> obj;
    obj.push('3');
    obj.push('y');
    obj.display();

    obj.push('d');
    obj.push('2');
    obj.push('a');
    obj.display();
    obj.pop();
    obj.display();
    

    
    return 0;
}