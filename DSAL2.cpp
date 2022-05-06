#include<iostream> 
using namespace std;

class list;
class node
{ 
    char data;
    node* next;
    public:

    node()
    {
        data ='\0';
        next = NULL;
    }

    node(char x)
    {
        data = x;
    }
    friend list;


};

class list
{
    node* head;
      node* tail;
    public:


	list()
	{
		head = NULL;
		tail = NULL;

	}
    // function to create a linked list.

	void creat(char y)
	{
        if(head == NULL)
		{
            node* temp = new node(y);
		    temp->next = NULL;
		    head = tail = temp ;
            cout<<" New list is created \n";
        }
        else{
            cout<<" List is already created"<<endl;
        }
	}
    // function to insert element at the start.

	void insert_start(char x)
	{
        if(head == NULL)
        {
            cout<<"No List exist \n";
          
        }
        else
		{
            node* temp = new node(x);
		    temp->next = head;
		    head = temp;
        }
	}
   

  
    
    // function to insert element at the end.

	void insert_end(char x)
	{
          if(head == NULL)
        {
            cout<<"No List exist \n";
        }

        else
		{
            node* temp = new node(x);
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
        }
	}

    // function to insert element at the mid.

    
    // void insert_mid(int loc, int x)
    // {
    //      node* temp = new node(x);
    //      node* ptr = head;
    //      int i = loc-1;
    //      while(i--)
    //      {
    //          ptr = ptr->next;

    //      }
    //      temp->next = ptr->next;
    //      ptr->next = temp;


    // }
    // function to delete element from the mid.

    // void delete_mid(int loc)
    // {
    //     node* ptr = head;
    //      int i = loc-2;
    //      while(i--)
    //      {
    //          ptr = ptr->next;

    //      }
    //      node* temp = ptr->next;
    //         cout<<"Element "<<temp->data<<" is deleted from the list \n";
    //         ptr->next = temp->next;
    //         delete temp;
        

    // }
    // function to display linked list.

	void display()
	{
        if(head== NULL)
        {
            cout<<"List is empty \n";
        }
        else
		{
            node* temp = head;
            cout<<" LIST : ";
		while(temp->next != NULL)
		{
			cout<<temp->data<<" -> ";
			temp = temp->next;

		}

        cout<<temp->data<<endl;
        }
		
	}
    void add_after()
    {
        node* temp = head;

        while(temp != NULL)
        {
            if(temp->data== 'a' || temp->data =='e'|| temp->data == 'i' || temp->data == 'o' || temp->data == 'u' ||temp->data == 'A'||temp->data == 'E'||temp->data == 'I'||temp->data == 'O'|| temp->data == 'U' )
            {
                node* n = new node('#');
                n->next = temp->next;
                temp->next = n;
                
                temp= n->next;
            }
            temp = temp->next;
        }
    }

    void delete_u_c()
    {
         node* temp = head;

        while(temp->next != NULL)
        {
            if(isupper(temp->next->data))
            {
                 if(temp->next->data != 'A'||temp->next->data != 'E'||temp->next->data != 'I'||temp->next->data != 'O'|| temp->next->data != 'U'|| temp->next->data != '#' )
            {
                node* n = temp->next;
                 cout<<"Element "<<n->data<<" is deleted from the list \n";
                
                temp->next = n->next;
                
                delete n;
            }
            

            }
           
            temp = temp->next;
        }

    }


};


int main(){
    string s;
    cout<<"enter a string : ";
    getline(cin, s);

    list obj;
    obj.creat(s[0]);

    for(int i =1; i<s.length();i++)
    {
        if(islower(s[i]))
        {
            obj.insert_start(s[i]);

        }
        else if(isupper(s[i]))
        {
            obj.insert_end(s[i]);
        }
        else{
            continue;
        }
    }
    obj.display();
    obj.add_after();
    obj.display();
    obj.delete_u_c();
    obj.display();


    return 0;
}