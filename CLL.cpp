#include<iostream> 
using namespace std;
class CLL;
class node
{
	int data;
	node* next;
  
public:
    node()
    {
        data =0;
        next  = NULL;
    }


	node(int x)
	{
		data = x;
	}
	friend CLL;
};
class CLL
{
    node* head;
    node* last;

    public:
    CLL()
    {
        head = last = NULL;
    }

    void create(int x)
    {
          if(head == NULL)
		{
            node* temp = new node(x);
		    temp->next = ;
		    head = last = temp ;
            cout<<" New list is created \n";
        }
        else{
            cout<<" List is already created"<<endl;
        }
    }
};


int main(){
    
    return 0;
}