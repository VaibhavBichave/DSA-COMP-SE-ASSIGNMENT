#include<iostream>

using namespace std;


class sll;

class node
{
	int data;
	node* next;
public:
    node()
    {
        data =0;
        next = NULL;
    }


	node(int x)
	{
		data = x;
	}
	friend sll;
};


class sll
{
	node* head;
    node* tail;
    public:


	sll()
	{
		head = NULL;
		tail = NULL;

	}
    // function to create a linked list.

	void creat(int y)
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
		    head = temp;
        }
	}
    // function to delete element from the start.

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
            delete temp;
        }
    }
    
    // function to insert element at the end.

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
		tail->next = temp;
		tail = temp;
        }
	}

    // function to delete element from the end.
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
    // function to insert element at the mid.

    
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
         ptr->next = temp;


    }
    // function to delete element from the mid.

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
            delete temp;
        

    }
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
		while(temp = NULL)
		{
			cout<<temp->data<<" -> ";
			temp = temp->next;

		}

        //
        cout<<temp->data<<endl;
        }
		
	}

    // function to reverse a linked list.
    void reverse_list()
    {
        node* prev = NULL;
        node* current = head  ;
        tail = current;
        node* nextptr ;
        while(current != NULL)
        {
           nextptr = current->next;
           current->next = prev;

           prev = current;
           current = nextptr;
          
        }
        head = prev;
    }
    // Reversing a linked list using recursion.

    // node* recrsive_reverse(node* &head)
    // {

    //     node*  newhead = recrsive_reverse(head->next);


    // }

    // function to reversr k noodes.

    // void reversek(int k)
    // {
    //      node* prev = NULL;
    //     node* current = head;
    //     node* nextptr ;
    //     int count =0;
    //     while(current != NULL && count<k)
    //     {
    //        nextptr = current->next;
    //        current->next = prev;

    //        prev = current;
    //        current = nextptr;
    //        count++;
          
    //     }
    //     head = prev;

    //     if(nextptr != NULL)
    //     {
    //         reversek(k);
    //     }

    // }

    
};

int main()
{
	sll  obj;
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
    obj.reverse_list();

     obj.display();
     obj.insert_end(13);
     obj.display();
    obj.reverse_list();
     obj.display();






	return 0;
}


