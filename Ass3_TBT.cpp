#include <iostream>
using namespace std;
 
class Node
{
    private:
        Node *left, *right; //data members
        int data;
        int rbit, lbit; // 1 for thread 0 for link
 
public:
    Node()
    { //constructot
        left = NULL;
        right = NULL;
        rbit = lbit = 0;
    }
    Node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
        rbit = lbit = 0;
    }
    friend class TBT;
};
 
class TBT
{
private:
    Node *root, *header; //data members
public:
    TBT()
    { //constructor
        root = NULL;
        header = new Node(999);
        header->right = header->left = header;
    }
    void insert(int d);   //insert node in the tree
    void inorder();       //inorder traversal
    void preorder();      //preorder traversal
    void deleteNode(int); //delete the node from tree
    Node *inSucc(Node *); //return inorder successor of that node
    Node *inPred(Node *); //return inorder predecessor of that node
};
 
void TBT::insert(int d)
{
    if (root == NULL)
    {
        //create a new node for root
        root = new Node(d);
        root->left = root->right = header;
        root->lbit = root->rbit = 1;  // 1 for thread
        header->left = root;
        header->lbit = 1;
        cout << "\n Data Inserted sucessfully" << endl;
    }
    else 
    {
        Node *curr = root;
        while (curr != header)
        {
            //moving to left subtree
            if (curr->data > d)
            {
                Node *p = new Node(d);
                if (curr->lbit == 1)
                {
                    p->left = curr->left;
                    curr->left = p;
                    p->lbit = 1;
                    curr->lbit = 0;
                    p->right = curr;
                    p->rbit = 1;
                    cout << "\n Data Inserted sucessfully" << endl;
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
            //moving to right subtree
            if (curr->data < d)
            {
                Node *p = new Node(d);
                if (curr->rbit == 1)
                {
                    p->right = curr->right;
                    curr->right = p;
                    p->rbit = 1;
                    curr->rbit = 0;
                    p->left = curr;
                    p->lbit = 1;
                    cout << "\n Data Inserted sucessfully" << endl;
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
    }
}
 
void TBT::inorder()
{
    Node *c = root;
    while (c->lbit == 0) //go to the leftmost node
        c = c->left;
    while (c != header)
    {
        cout << c->data << "  ";
        if (c->rbit == 0)
        {
            c = c->right;
            while (c->lbit == 0)
                c = c->left;
        }
        else
            c = c->right;
    }
}
void TBT::preorder()
{
    Node *temp = root;
    while (temp != header)
    {
        while (temp->lbit == 0)
        {
            cout << temp->data << " ";
            temp = temp->left;
        }
        cout << temp->data << " ";
        while (temp->rbit == 1)
        {
            temp = temp->right;
            if (temp == header)
                return;
        }
        temp = temp->right;
    }
}
 
Node *TBT::inSucc(Node *ptr)
{
    if (ptr->rbit == 1)
        return ptr->right;
    ptr = ptr->right;
    while (ptr->lbit == 0)
        ptr = ptr->left;
    return ptr;
}
 
Node *TBT::inPred(Node *ptr)
{
    if (ptr->lbit == 1)
        return ptr->left;
    ptr = ptr->left;
    while (ptr->rbit == 0)
        ptr = ptr->right;
    return ptr;
}

 
void TBT::deleteNode(int x)
{
    if (header->left == NULL)
    {
        cout << "Tree is Empty!!" << endl;
        return;
    }
    Node *temp = header->left;
    Node *parent = header;
    int found = 0;
    while (temp != header)
    {
        if (temp->data == x)
        {               
            found = 1;
            break;
        }
        else if (temp->data > x)
        {
            if (temp->lbit == 1)
            {
                cout << "Element not found!!" << endl;
                return;
            }
            parent = temp;
            temp = temp->left;
        }
        else if (temp->data < x)
        {
            if (temp->rbit == 1)
            {
                cout << "Element not found!!" << endl;
                return;
            }
            parent = temp;
            temp = temp->right;
        }
    }
//node to be deleted has two children
    if (temp->lbit == 0 && temp->rbit == 0)
    {
        //find inorder successor
        Node *successor = temp->right;
        Node *p_successor = temp;
        Node *child = NULL;
 
        //find leftmost child of successor
        while (successor->lbit != 1)
        {
            p_successor = successor;
            successor = successor->left;
        }
 
        temp->data = successor->data;
        if (successor->lbit == 1 && successor->rbit == 1)
        {
            if (p_successor == temp)
            {
                p_successor->right = successor->right;
                p_successor->rbit = 1;
                delete successor;
                cout << "Node deleted!!" << endl;
                return;
            }
 
            p_successor->left = successor->left;
            p_successor->lbit = 1;
        }
        else
        { //successor has a right child
            p_successor->left = successor->right;
            child = successor->right;
            child->left = successor->left;
        }
        delete successor;
        cout << "Node deleted!!" << endl;
        return;
    }
//node to be deleted has only one child
    else if (temp->lbit == 0 || temp->rbit == 0)
    {
        Node *child = NULL;
        //initialize the child node
        if (temp->lbit == 0)
        {
            child = temp->left;
        }
        else
        {
            child = temp->right;
        }
 
        // node to be deleted is root node
        if (temp == root)
        {
            header->left = child;
            root = child;
        }
        //node to deleted is left child of its parent
        else if (parent->left == temp)
        {
            parent->left = child;
        }
        //node to be deleted is right child of its parent
        else
        {
            parent->right = child;
        }
        //find succsssor and predecessoe
        Node *s = inSucc(temp);
        Node *p = inPred(temp);
 
        //if temp has left subtree
        if (temp->lbit == 0)
        {
            p->right = s;
        }
        //if temp has right subtree
        else
        {
            s->left = p;
        }
 
        delete temp;
        cout << "Node deleted!!" << endl;
        return;
    }
//node to be deleted has no child
    else
    {
        //if node to be deleted is root
        if (temp == root)
        {
            header->left = NULL;
            root = NULL;
        }
        //if node to be deleted is left child of it's parent
        else if (parent->left == temp)
        {
            parent->lbit = 1;
            parent->left = temp->left;
        }
        //if node to be deleted is right child of it's parent
        else
        {
            parent->rbit = 1;
            parent->right = temp->right;
        }
        delete temp;
        cout << "Node deleted!!" << endl;
        return;
    }
}
 
int main()
{
    TBT t1;
    int ch;
    while (true)
    {
        cout << "\n<<-----MENU----->>" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Inorder Traversal " << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int n;
            cout << "\nEnter number of Nodes:";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int data;
                cout << "\nEnter data: ";
                cin >> data;
                t1.insert(data);
            }
            break;
        }
        case 2:
        {
            cout << "Inorder Traversal : " << endl;
            t1.inorder();
            break;
        }
        case 3:
        {
            cout << "Preorder Traversal: " << endl;
            t1.preorder();
            break;
        }
        case 4:
        {
            int key;
            cout << "\nEnter value to be delete: " << endl;
            cin >> key;
            t1.deleteNode(key);
            cout << "Data deleted successfully!!!" << endl;
            break;
        }
        case 5:
            exit(1);
            break;
        default:
            cout << "Please ,enter valid choice!!" << endl;
        }
    }
    return 0;
}
 
