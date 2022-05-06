#include<iostream> 
#include "queue.h"
#include <stack>
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
    node1* root;
    public:

    tree()
    {
        root = NULL;
    }

    void set_root(node1* T)
    {
        root = T;
    }
    node1* getroot()
    {
        return root;
    }

    // Non Recursive creation
    void creat()
    {
        
          queue<node1* > q;
        int x;
        cout<< " Enter an element : ";
        cin>> x;
       
        
            node1* p = new node1(x);
            root = p;
            q.push(root);

        
        
        
        while(!q.empty())
        {
            node1* temp = q.get_front();
             q.pop();
            
        
           
             char c;
                cout<<temp->data<< " root have left child ? (y/n)  : ";                                                     
                                    

                cin >> c;
                if( c == 'y')
                {
                     int x;
                    cout<< " Enter an element : ";
                    
                    cin>> x;
                    node1* ptr = new node1(x);
                    temp->lchild = ptr;
                    q.push(ptr);
                  
                    
                }

                char d;
                cout<<temp->data<< " root have right child ? (y/n)  : ";
                cin >> d;
                 if( d == 'y')
                {
                     int x;
                    cout<< " Enter an element : ";
                    cin>> x;
                    node1* p = new node1(x);
                    temp->rchild = p;
                    q.push(p);
                 //}
                   
                }


        
        }
    }

    // Recursive Creation
 
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

        // Inorder Traversal (Recursive method)
      void inorder(node1* temp)
    {
        if(temp == NULL)
            return;
        
            inorder(temp->lchild);
            cout<<temp->data<<" ";
            inorder(temp->rchild);
        
    }

    // Preorder Traversal (Recursive method)
    void preorder(node1* temp)
    {
          if(temp == NULL)
            return;
            cout<<temp->data<<" ";
            preorder(temp->lchild);
            
            preorder(temp->rchild);
    }

    // Postorder Traversal (Recursive method)
     void postorder(node1* temp)
    {
          if(temp == NULL)
            return;
            
            postorder(temp->lchild);
            
            postorder(temp->rchild);

            cout<<temp->data<<" ";
    }

    // Inorder Traversal (Non- Recursive)

    void Non_rec_inorder ( node1* T)
    {
            stack<node1*> s;
        while(1)
        {
    
        while(T!= NULL)
        {
            s.push(T);
            T = T->lchild;
        }

        if(s.empty())
            return;

        T = s.top();
        s.pop();
        cout <<T->data<<" ";
        T = T->rchild;
        }

    }
    // Preorder Traversal (Non- Recursive)


     void Non_rec_preorder ( node1* T)
    {
            stack<node1*> s;
        while(1)
        {
    
        while(T!= NULL)
        {
            s.push(T);
            cout <<T->data<<" ";
            T = T->lchild;
        }

        if(s.empty())
            return;

        T = s.top();
        s.pop();
      
        T = T->rchild;
        }


    }

    // Postorder Traversal (Non- Recursive)



      void Non_rec_postorder ( node1* T)
    {
            stack<node1*> s1,s2;
            if(T ==NULL)
            {
        
                return;
            }
            s1.push(T);
            while(!s1.empty())
            {
                node1* ptr =s1.top();

                s2.push(ptr);
                s1.pop();

                   // Push the left child of the top element
                if(s2.top()->lchild!= NULL)
                {
                    s1.push(s2.top()->lchild);
                }
                 // Push the right child of the top element
                  if(s2.top()->rchild!= NULL)
                {
                    s1.push(s2.top()->rchild);
                }

            }    
            // Print the second stack
             while(!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    cout << endl;
       
     }
     

     // Function to find height of a tree Recursively

     int Height_of_tree(node1* T)
     {
         if(T== NULL)
         {
             return 0;
         }
         if(T->lchild == NULL && T->rchild == NULL)
         {
             return 1;
         }
         int h1 = Height_of_tree(T->lchild);
         int h2 = Height_of_tree(T->rchild);

         if(h1>h2)
            return (h1+1);
        else
            return (h2+1);

     }

     // Mirror image of tree

     void mirror_img(node1* T)
     {
         if(T==NULL)
            return;

         node1* temp ;
         mirror_img(T->lchild);
         mirror_img(T->rchild);
         temp = T->lchild;
         T->lchild = T->rchild;
         T->rchild = temp;


     }

     // Function to Count Leaf node and Internal node (non rec).
     void count(node1* T)
     {
         queue<node1*> q;
         q.push(T);
         int Inode =0, Lnode =0;

         while(!q.empty())
         {
             node1* temp = q.get_front();
             q.pop();
             if(temp->lchild == NULL && temp->rchild == NULL)
             {
                 Lnode++;
             }
             else
             {
                 Inode++;

             }
             if(temp->lchild != NULL)
             {
                 q.push(temp->lchild);
             }

              if(temp->rchild != NULL)
             {
                 q.push(temp->rchild);
             }
         }

         cout<< " Number of leaf nodes are : "<<Lnode<<endl; 
         cout<< " Number of internal  nodes are : "<<Inode<<endl; 
     }
     
     //count leaf node recursively

     void Leaf(node1* T)
     {
         if(T == NULL)
            return;

        Leaf(T->lchild);
        Leaf(T->rchild);

        int Lcount =0;

        if(T->lchild == NULL && T->rchild == NULL)
             {
                 Lcount++;
                 cout<<" Leaf Nodes  : "<<T->data<<" ";

             }
          
            //  else
            //  {
            //         cout<< endl;
            //       cout << " Leaf nodes count : "<<Lcount<<endl;
            //  }
               

        
     }

     // rec internal node counting
     void Inode(node1* T)
     {
          if(T == NULL)
            return;

        Inode(T->lchild);
        Inode(T->rchild);

        int Icount =0;

        if(T->lchild != NULL || T->rchild != NULL)
             {
                
                 cout<<" Interrnal Nodes  : "<<T->data<<" ";
                  Icount++;

             }
            //  else
            //  {   cout<< endl;
            //  cout << " Internal  nodes count : "<<Icount<<endl;

            //  }
          
     }

     // Copy tree 

     node1* Copy_Tree(node1* T)
     {
         node1* c = NULL;
         if(T == NULL)
            return NULL;
        c = new node1(T->data);
        c->lchild = Copy_Tree(T->lchild);
        c->rchild = Copy_Tree(T->rchild);
        return c;
     }

    node1* operator=(tree obj )
    {
       node1* T;
       T = obj.Copy_Tree(obj.getroot());
       return T;
    }

    // Delete tree

    void del_tree(node1* T)
    {
        if(T== NULL)
        {
            return;
        }
        del_tree(T->lchild);
        del_tree(T->rchild);

          cout << "\n Deleting node: " << T->data;
    delete T;

    }





};


int main(){

    tree obj;
    tree o2;


   int n;
   
char c='y';
while(c=='y')
{ 
cout<<"\n*********************************************\n";
cout<<" Binary Tree \n ";
cout<<"*********************************************\n";
cout<<"Enter a Choice : "<<endl;
cout<<"1.  Recursive Tree Creation "<<endl;
cout<<"2.  Non-Recursive Tree Creation "<<endl;
cout<<"3.  Recursive Tree Travarsal  "<<endl;
cout<<"4.  Non-Recursive Tree Traversal  "<<endl;
cout<<"5.  Calculate Height of Tree "<<endl;
cout<<"6.  Mirror Image  of Tree "<<endl;
cout<<"7.  count number of Leaf nodes and Internal nodes "<<endl;
cout<<"8.  copy tree  "<<endl;
cout<<"9.  Delete tree  "<<endl;


cin>>n;
switch(n)
{
case 1:obj.set_root(obj.rec_create());
break;
case 2: obj.creat();
break;
case 3:
        cout<<" Traversing Tree Recursively \n";
                cout<<" Inorder : ";
                obj.inorder(obj.getroot());
              cout<<endl;
              
                
           cout<<" Preorder : ";
                obj.preorder(obj.getroot());
              cout<<endl;

                cout<<" Postorder : ";
                obj.postorder(obj.getroot());
              cout<<endl;
    break;
case 4: 

        cout<<" Traversing Tree  Non-Recursively \n";

                cout<<" Inorder : ";
    
                obj.Non_rec_inorder(obj.getroot());
              cout<<endl;
           cout<<" Preorder : ";

                obj.Non_rec_preorder(obj.getroot());
              cout<<endl;
                cout<<" Postorder : ";

                obj.Non_rec_postorder(obj.getroot());
              cout<<endl;
  

    break;

case 5:
        cout<<" Height of tree is  : "<<obj.Height_of_tree(obj.getroot())<<endl;
        break;

case 6:
        cout<<" Mirror image of tree is created"<<endl;
        obj.mirror_img(obj.getroot());
        break;

case 7:
       obj.Leaf(obj.getroot());
       cout<<endl;
       obj.Inode(obj.getroot());
       cout<<endl;

        obj.count(obj.getroot());
       cout<<endl;



        break;

case 8:
    o2.set_root(o2 = obj);
    
    cout<< " New tree is created, Traversing new tree "<<endl;
     cout<<" Inorder : ";
    
                o2.Non_rec_inorder(o2.getroot());
              cout<<endl;
           cout<<" Preorder : ";

                o2.Non_rec_preorder(o2.getroot());
              cout<<endl;
                cout<<" Postorder : ";

                o2.Non_rec_postorder(o2.getroot());
              cout<<endl;
     break;

case 9:
        obj.del_tree(obj.getroot());
        cout<<" \n Tree is Deleted"<<endl;
        break;


default: cout<<"Wrong choice input\n";
}
cout<<"\nDo you want to perform any other operation : (y/n)\n";
cin>>c;
}

    
    return 0;
}