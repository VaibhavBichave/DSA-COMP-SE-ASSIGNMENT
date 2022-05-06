#include <iostream>
using namespace std;

template <class T>
class Queue;


template <class T>
class Node
{
    T data;
    Node<T>* next;
    public:
        Node<T>()
        {
            data=0;
            next=NULL;
        }

        Node<T>(T val){
            data=val;
            next=NULL;
        }

    friend class Queue<T>;
};

template <class T>
class Queue
{
    Node<T> *front,*rear;

    public:
        Queue<T>()
        {
            front=rear=NULL;
        }

        Node<T>* getfront(){
            return front;
        }

        void push(T val){
            Node<T> *temp = new Node<T>(val);

            if(front==NULL){
                front=rear=temp;
                return;
            }
            rear->next = temp;
            rear = temp;
        }

        void dequeue(){
            if(!isEmpty()){
                Node<T>* todelete = front;
                front = front->next;
                delete todelete;
            }
            else{
                cout<<"Queue underflow"<<endl;
            }
        }

        void display(){
            Node<T> *temp = front;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        bool isEmpty(){
            return front==NULL;
        }
};