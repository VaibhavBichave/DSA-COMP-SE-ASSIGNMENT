// que 1
#include<iostream> 
using namespace std;

  class node
    {
        public:
    
        int data;
        node* next;
        node()
        {
            data = 0;
            next = NULL;
            
        }
       

    };
class list
{
  
    node* head;
   
    public:
    list()
    {
         head = NULL;
        
    }
  
       

    
    void insert_start( int x)
    {
        node* ptr = new node;
        ptr->data = x;
        if(head == NULL)
        {
            head = ptr;
        }

        ptr->next = head;
        head = ptr; 

    }
    void insert_end(int y)
    {
        node* ptr = new node;
        ptr->data = y;
        if(head == NULL)
        {
            head = ptr;
        }
        node* temp = head;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;

    }
    void display()
    {
        node* temp ;
        temp = head;
        while(temp->next != NULL)
        {
            cout << temp->data<<"->"<<" ";
            temp = temp->next;
        }
        cout<<temp->data;
        cout <<endl;
    }
    int sum()
    {
         node*temp = head;
        int sum = 0;
          while(temp->next != NULL)
        {
           sum += temp->data;
         
                 temp = temp->next;
          
        }
        sum += temp->data;
        return sum; 
    }

    int sum_odd()
    {
        node*temp = head;
        int count = 0;
        int sumodd = 0;
          while(temp != NULL)  // 23 35 38 24 72 56
        {
            if(count%2 ==0 )
            {
                sumodd += temp->data;

            }
            count++;
            
           // if(temp->next!= NULL)
              temp = temp->next;
        
          
        }
         //sumodd += temp->data;
        return sumodd;


    }
    bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

    int sum_prime()
    {
        node* temp = head;
        int sum_prime = 0;
         while(temp != NULL)  
        {
            if(isPrime(temp->data))
            {
              sum_prime += temp->data;

            }
          
            
        
              temp = temp->next;
        
          
        }
        return sum_prime;

    }

};
int sum_digits(int a)
{
    int sum = 0;
    while(a)
    {
        sum = sum + (a%10);
        a = a/10;
    }
    return sum;
}



int main(){
  
    list obj;
    int n , c;
    cout<<"How many numbers you want to add :";
    cin>> c;
    for(int i = 0; i< c;i++)
    {
    cout<<"Enter the number you want to insert :";
    cin>>n;
   int s = sum_digits(n);

    if(s%2== 0)
    {
        obj.insert_start(n);

    }
    else
    {
          obj.insert_end(n);
    

    }
  
    }

  
    
    obj.display();
    cout<<" sum of numbers in the list is :";
  cout<<  obj.sum();
  cout<<endl;
  cout<<"sum of odd places numbers is :";
  cout<< obj.sum_odd();
  cout<<endl;

  cout<<"sum of even places numbers is :";
  int w = obj.sum() - obj.sum_odd();

  cout <<  w <<endl;

  cout<< "sum of prime numbers is : ";
  cout << obj.sum_prime();

   

    
    
    return 0;
}