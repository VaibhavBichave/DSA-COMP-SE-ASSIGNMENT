#include <iostream>
#include "Queue1.h"
using namespace std;

// template <class t>
// class Tree;

//template <class t>
class Node1
{
    int data;
    Node1* left;
    Node1* right;

    public:
        Node1()
        {
            data=0;
            left = right = NULL;
        }

        Node1(int val){
            data = val;
            left = right = NULL;
        }
    
    friend class Tree;
};

//template <class t>
class Tree
{
    Node1* root;

    public:
        Tree(){
            root = NULL;
        }

        Node1* getRoot(){
            return root;
        }

        void createTree(){
            Queue<Node1*> q;

            cout<<"Enter the element"<<endl;
            int ele;
            cin>>ele;
            Node1* p = new Node1(ele);
            if(root==NULL){
                root = p;
                q.push(root);
            }
             //else{
                while (!q.isEmpty())
                {
                    //int frontval = new node(q.front());
                    Node<Node1*>* temp = q.getfront();
                    Node1* s = (Node1*) temp;
                    q.dequeue();

                    char lchild,rchild;
                    cout<<"Does "<<s->data<<" have any left child? (Y/N)"<<endl;
                    cin>>lchild;
                    if(lchild=='Y'){
                        cout<<"Enter the element"<<endl;
                        int lc;
                        cin>>lc;
                        Node1* newleft = new Node1(lc);
                        s->left = newleft;
                        q.push(newleft);
                    }
                    cout<<"Does "<<s->data<<" have any right child? (Y/N)"<<endl;
                    cin>>rchild;
                    if(rchild=='Y'){
                        cout<<"Enter the element"<<endl;
                        int rc;
                        cin>>rc;
                        Node1* newright = new Node1(rc);
                        s->right = newright;
                        q.push(newright);
                    }
                //}
            }
            
        }

        void inorder(Node1* temp){
            if(temp==NULL){
                return;
            }
            inorder(temp->left);
            cout<<temp->data<<" ";
            inorder(temp->right);
        }
};

int main()
{
    Tree bt;

    
    bt.createTree();
    Node1* root = bt.getRoot();
    bt.inorder(root);

}

