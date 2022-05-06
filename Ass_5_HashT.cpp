#include<iostream> 
using namespace std;
#define size 997

class He
{
    string word;
    string meaning;

    He* next;

    public:

    He()
    {
        word = "";
        meaning = "";
        next = NULL;
    }
    He(string w, string m)
    {
        word = w;
        meaning = m;
        next = NULL;
    }

    friend class Dict;
};

class Dict
{
    He* Ht[size];

    int Hash_func(string key)
    {

        int hi = 0;
        for(int i =0; i<key.length();i++)
        {
            hi += int(key[i])*(i+1);
        }

        return hi%size;
    }

    public:

    Dict()
    {
        for(int i =0; i<size; i++)
        {
            Ht[i] = NULL;
        }
    }
   

    void insert(string key , string mean);
 
    void Display();
    
    void search(string key);

    He* search_pos(string key);

    void Delete(string key );

    void update_meaning(string key, string new_value  );
  
};

     void Dict :: insert(string key , string mean)
    {
        He* test = search_pos(key);

    if(test == NULL)
    {
        He* temp = new He(key,mean);

        int ha = Hash_func(key);

        if(Ht[ha] == NULL)
        {
            Ht[ha] = temp;
        }

        else
        {
            He* ptr = Ht[ha];

            while(ptr->next != NULL)
            {
                ptr = ptr->next;

            }
            ptr->next = temp;

        }
    }

    else
    {
        cout << " key is already present \n ";
        return ;
    }

    }

     void Dict :: Display()
    {
        for(int i = 0; i < size; i++)
        {
            He* ptr = Ht[i];

            if(ptr == NULL )
            {
                continue;
            }
            while(ptr != NULL)
            {
                cout << i << " "<< ptr->word << " - "<<ptr->meaning << " -> ";
                ptr = ptr->next;
            }
            cout <<endl;

        }
    }

     void Dict :: search(string key)
    {
        int hi = Hash_func(key);

        if(Ht[hi] == NULL)
        {
            cout << " Key is not present  \n ";

        }
        int counter =1 ;
        He* temp = Ht[hi];
        bool flag = 0;
        while(temp != NULL)
        {
            if(temp->word  == key)
            {
                cout <<" Key is found after "<<counter << " number of comparisions \n";

                cout << "Key  = "<<temp->word<< "  meaning =  "<<temp->meaning<<endl;
                flag =1;

                break;

            }
            else 
            {
                counter++;
                temp = temp->next;

            }
            if(flag == 0)
            {
                cout << " Key is not found"<<endl;
            }

        }

    }
     void Dict ::  Delete(string key )
    {
        int hi = Hash_func(key);

        He* ptr = Ht[hi];
        He* prev = NULL;

        if( ptr != NULL && ptr->word == key)
        {
           Ht[hi] = ptr->next;
           delete ptr;
           return ;
        }
        else
        {

            while(ptr->next->word != key && ptr!= NULL)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            if(ptr == NULL)
            {
                cout << " Key is not present \n";

            }
            prev->next = ptr->next;

            delete ptr;

        }


    
        
        
        
    }
     He* Dict :: search_pos(string key)
     {
         int hi = Hash_func(key);

         He* ptr = Ht[hi];
         if(ptr == NULL)
         {
             return ptr;
         }

         else
         {
             while( ptr->word != key && ptr != NULL)
             {
                 ptr = ptr->next;

             }
             return ptr;

         }
     }

    void Dict :: update_meaning(string key , string new_value )
    {
        He* ptr = search_pos(key);

        if(ptr != NULL)
        {
            ptr->meaning = new_value;
            cout << " Meaning updated successfully "<<endl;
        }

        else{
            cout << " Key is not present \n";

        }
    }


 
int main(){

    Dict obj;
    string key , value;
int n ;
char c='y';
while(c=='y')
{ 
cout<<"\n*********************************************\n";
cout<<" Dictonary (using hash table ) \n ";
cout<<"*********************************************\n";
cout<<"Enter a Choice : "<<endl;
cout<<"1.  Insert   "<<endl;
cout<<"2.  Update Meaning  "<<endl;
cout<<"3.  Disply     "<<endl;
cout<<"4.  Search   "<<endl;
cout<<"5.  Delete   "<<endl;


cin>>n;
switch(n)
{
case 1:
	
	cout  << " Enter key  : ";
	cin >> key;
	cout << " Enter value : ";
	cin >>value;

	obj.insert(key, value);


break;
case 2:
	
	cout  << " Enter key  : ";
	cin >> key ;
	cout << " Enter New meaning : ";
	cin >>value;

	obj.update_meaning(key,value);


break;
case 3:
               obj.Display();
    break;
case 4: 
			
            cout<< " Enter key want to search : ";
			cin >> key;

			obj.search(key);

    break;

case 5:
        cout <<" Enter key want to Delete "<<endl;
        cin >>key;

        obj.Delete(key);
        break;


default: cout<<"Wrong choice input\n";
}
cout<<"\nDo you want to perform any other operation : (y/n)\n";
cin>>c;
}

    



    
    return 0;
}