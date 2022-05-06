#include<iostream> 
using namespace std;
class tree;
class node1
{
    int data;
    node1* lchild;
    node1* rchild;
    public:
    node1(int x)
    {
        data = x;
        lchild = NULL;
        rchild = NULL;
    }
    friend tree;

   
};

class tree
{
    public:
    node* root;

    tree()
    {
        root = NULL;
    }
     node1* rec_create()
    {
        int x;
        cout<<"Enter data or -1 for no data :";
        cin >>x;
        if(x== -1)
        {
            return NULL;
        }
        node1* p =new node1(x);
        cout<<" Enter left child data of :"<<x<<" : ";
         p->lchild = rec_create();
         cout<<" Enter right child data  of :"<<x<<" : ";
         p->rchild = rec_create();

         return p;

    }

    void DFS_Rec(node* root)
    {
        if(root != NULL)
        {
            cout << root->data
        }
    }


};
int main(){
    
    return 0;
}