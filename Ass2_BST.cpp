#include<iostream> 
#include<string>

using namespace std;

class Dictionary;
class Node
{
    string word, meaning;
    Node* lchild,*rchild;
    public:
    
    Node()
    {
        lchild =NULL;
        rchild = NULL;
    }
    Node(string w, string m)


    {
        word = w;
        meaning = m;
        lchild =NULL;
        rchild = NULL;
    }
    friend class Dictionary;

};

class Dictionary
{
    Node* root;

    public:
    Dictionary()
    {
        root = NULL;
    }
    Node* Get_root()
    {
        return root;
    }


    void create();
    bool insert(string word,string meaning);
    Node* search(string key);
    void updt_meaning(string word, string new_meaning);
    void Display_Assending(Node* T);
    void Display_Desending(Node* T);
    int search(string key, Node*&loc, Node*&parent);  
    void search_count(string key);
    void Delete_key(string key);
    void Del1(string key, Node* loc, Node* par);
    void Delete2(string key, Node* loc, Node* par);



};


void Dictionary::create()
{
 int n;
 string wordI,meaningI;
 cout<<"\nHow many Word to insert? : ";
 cin>>n;
 while(n--)
 {
  cout<<"\nEnter Word: ";
  cin>>wordI;
  cout<<"\nEnter Meaning: ";
  cin>>meaningI;
  insert(wordI,meaningI);
 }
}

bool Dictionary::insert(string word, string meaning)
{
 Node *p=new Node(word, meaning);
 if(root==NULL)
 {
  root=p;
  return true;
 }
 Node *cur=root;
 Node *par=root;
 while(cur!=NULL) //traversal
 {
  if(word>cur->word)
  {par=cur;
  cur=cur->rchild;
  }
  else if(word<cur->word)
  {
   par=cur;
   cur=cur->lchild;
  }
  else
  {
   cout<<"\nWord is already in the dictionary.";
   return false;
  }
 }
 if(word>par->word) //insertion of node
 {
  par->rchild=p;
  return true;
 }
 else
 {
  par->lchild=p;

  return true;
 }
}

Node* Dictionary::search(string key)
{
 Node *tmp=root;
 
 int count = 0;
 if(tmp==NULL)
 {
  return NULL;
 }
 if(root->word==key)
  return root;
 while(tmp!=NULL)
 {

  if((tmp->word)>key)
  {
   tmp=tmp->lchild;
   count++;
  }
  else if((tmp->word)<key)
  {
   tmp=tmp->rchild;
   count++;
  }
  else if(tmp->word==key)
  {
   return tmp;
  }
 }
 return NULL;

}

void Dictionary :: updt_meaning(string word, string new_meaning)
{
      Node *loc=nullptr;
    Node *par=nullptr;
    int c=search(word,loc,par);
    if(loc==nullptr){
        cout<<"element not found"<<endl;
    }
    else{
        loc->meaning=new_meaning;
    }
}

void Dictionary :: Display_Assending(Node* T)
{
    if(T== NULL)
    {
        return;
    }
        Display_Assending(T->lchild);
        cout<< T->word <<" : "<< T->meaning<<endl;
        Display_Assending(T->rchild);

    
}
void Dictionary :: Display_Desending(Node* T)
{
    if(T== NULL)
    {
        return;
    }
        Display_Desending(T->rchild);
        cout<< T->word <<" : "<< T->meaning<<endl;
        Display_Desending(T->lchild);
}
int Dictionary :: search(string key , Node* &loc, Node* &par)
{
    int count = 0;
    Node* ptr = root;
    if(root == NULL)
        return 0;
    
    else
    {
        while(ptr!= NULL)
        {
            count++;
            if(ptr->word == key)
            {
                loc = ptr;
                return count;
            }
            else if(ptr->word>key)
            {
                par = ptr;
                ptr = ptr->lchild;
            }
            else
            {
                par = ptr;
                ptr = ptr->rchild;

            }
        }

    }
}
    
    void Dictionary :: search_count(string key)
    {
        Node* loc=NULL;
        Node* par=NULL;
        int c=search(key,loc,par);
        if(loc==NULL){
        cout<<"element Not found"<<endl;
        }
        else{
        cout<<"element found after "<<c<<" comparission"<<" has parent "<<par->word<<endl;
        }
    }

    

    void Dictionary:: Del1(string key, Node* loc, Node* par)
    {
        Node* child = NULL;
        if(loc->lchild!= NULL)
        {
            child = loc->lchild;
        }
        else
        {
            child = loc->rchild;
        }

        if(par->lchild == loc)
        {
            par->lchild = child;
        }
        else
        {
            par->rchild = loc;
        }

        delete loc;
        return;
    }

    void Dictionary :: Delete2(string key, Node* loc, Node* par)
    {
        Node* ptr = loc->rchild;
        Node* ptrpar = NULL;

        while(ptr!=NULL)
        {
            ptrpar = ptr;
            ptr = ptr->lchild;
        }
        loc->word = ptr->word;
        loc->meaning  = ptr->meaning;

        Del1(ptr->word,ptr,ptrpar);
    }

    void Dictionary :: Delete_key(string key)
    {
        Node *loc = nullptr,*par = nullptr;

        int c=search(key,loc,par);

        if(loc == nullptr){
        cout << "Element not found" << "\n";
        return;
        }

        if(loc != nullptr && par==nullptr){
        if(loc->lchild == nullptr && loc->rchild == nullptr){
            root = NULL;
            delete root;
        return;
        }
        }

        if(loc->lchild != nullptr && loc->rchild != nullptr){
        Delete2(key,loc,par);                                //both childs are present.
        }
        else{
        Del1(key,loc,par);
        }

    }




int main()
{
  
    Dictionary obj;
   // tree o2;
   string s1, s2;


   int n;
   
char c='y';
while(c=='y')
{ 
cout<<"\n*********************************************\n";
// cout<<" Binary Tree \n ";
// cout<<"*********************************************\n";
cout<<"Enter a Choice : "<<endl;
cout<<"1.  Create a Dictionary "<<endl;
cout<<"2.  Insert into Dictionary "<<endl;
cout<<"3.  Display  in Assending order  "<<endl;
cout<<"4.  Display in Desending order  "<<endl;
cout<<"5.  Calculate number  of comparisions for searching  "<<endl;
cout<<"6.  Upadate meaning "<<endl;
cout<<"7.  Delete Keyword  "<<endl;


cin>>n;
switch(n)
{
case 1:obj.create();
break;
case 2:
    cout<<" Enter a word  and meaning to insert : "<<endl;
    
    cout<<" Enter word  : ";
    cin>>s1;
    cout<<" Enter  meaning  : ";
    cin>>s2;
    cout<<endl;  

 obj.insert(s1,s2);
break;
case 3:
        cout<<"  Displaying in Assending order \n";
                obj.Display_Assending(obj.Get_root());
    break;
case 4: 
        cout<<"  Displaying in Desending order \n";
                obj.Display_Desending(obj.Get_root());

    break;

case 5:
        cout<<"Enter the element you want to search "<<endl;
        cin>>s1;
        obj.search_count(s1);
        break;

case 6:
        cout<<"Updating the meaning of the particular word"<<endl;
        cout<<"enter the word you want to change the meaning"<<endl;
        cin>>s1;
        cout<<"enter the meaning after the change"<<endl;
        cin>>s2;
        obj.updt_meaning(s1,s2);
        cout<<" Meaning is updated \n ";
        obj.Display_Assending(obj.Get_root());
        break;

case 7:
          cout<<"enter the keyword you want to delete"<<endl;
        cin>>s1;
        obj.Delete_key(s1);
        cout<<"keyword deleted successfully!"<<endl;
        obj.Display_Assending(obj.Get_root());
        break;



default: cout<<"Wrong choice input\n";
}
cout<<"\nDo you want to perform any other operation : (y/n)\n";
cin>>c;
}

    
    return 0;
}