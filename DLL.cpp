#include<iostream> 
using namespace std;
class DLL;
class node
{
	int data;
	node* next;
    node* prev;
public:
    node()
    {
        data =0;
        next = prev = NULL;
    }


	node(int x)
	{
		data = x;
	}
	friend DLL;
};

class DLL
{
    node* head;
    node* tail;
    public:


	DLL()
	{
		head = NULL;
		tail = NULL;

	}
    void creat(int y)
	{
        if(head == NULL)
		{
            node* temp = new node(y);
		    temp->next = temp->prev = NULL;
		    head = tail = temp ;
            cout<<" New list is created \n";
        }
        else{
            cout<<" List is already created"<<endl;
        }
	}
    void insert_start(int x)
	{
        if(head == NULL)
        {
            cout<<"No List exist \n";
          
        }
        else
		{
            node* temp = new node(x);
		    temp->next = head;
            temp->prev = NULL;
		    head->prev = temp;
            head = temp;
        }
	}
    void delete_start()
    {
        if(head == NULL)
        {
            cout<<"No elements exist \n";

        }
        else
        {
            node* temp = head;
            cout<<"Element "<<temp->data<<" is deleted from start \n";
            head = temp->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void insert_end(int x)
	{
          if(head == NULL)
        {
            cout<<"No List exist \n";
        }

        else
		{
        node* temp = new node(x);
		temp->next = NULL;
        temp->prev = tail;
		tail->next = temp;
        
		tail = temp;
        }
	}
    void delete_end()
    {
         if(head == NULL)
        {
            cout<<"No List exist \n";
        }

        else
        {
            node* current = head;
            node* prev = NULL;
            while(current->next != NULL)
            {
                prev = current;
                current = current->next;
               // prev = prev->next;
                
            }
            tail = prev;
            
             cout<<"Element "<<current->data<<" is deleted from end \n";
             prev->next= NULL;
           
            delete current;


        }


        
    }

     void insert_mid(int loc, int x)
    {
         node* temp = new node(x);
         node* ptr = head;
         int i = loc-1;
         while(i--)
         {
             ptr = ptr->next;

         }
         temp->next = ptr->next;
         temp->prev = ptr;
         ptr->next->prev = temp;
         ptr->next = temp;


    }

    void delete_mid(int loc)
    {
        node* ptr = head;
         int i = loc-2;
         while(i--)
         {
             ptr = ptr->next;

         }
         node* temp = ptr->next;
            cout<<"Element "<<temp->data<<" is deleted from the list \n";
            ptr->next = temp->next;
            ptr->next->prev = ptr;
            delete temp;
        

    }

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
			cout<<temp->data<<" <=> ";
			temp = temp->next;

		}
        cout<<temp->data<<endl;
        }
		
	}




};

int main(){

    DLL obj;
   obj.display();
    //obj.insert_end(8);
    obj.delete_end();
	 obj.creat(5);
	obj.insert_end(7);
    obj.insert_start(9);

	 obj.insert_start(3);
	 obj.display();
     obj.insert_mid(3, 4);
     obj.insert_mid(2,69);
	obj.insert_end(75);
    obj.insert_start(49);
     obj.display();

  obj.delete_end();
     obj.display();


obj.delete_start();
obj.display();
obj.delete_mid(3);


     
     obj.display();

    
    return 0;
}