#include<iostream>
using namespace std;
#define size 10


class Hash_entry
{
	long long int key ;
	string val ;
public:
	Hash_entry()
	{
		key  =  -1;
		val = "";
	}
	

	friend class HT;
};

class HT
{
	Hash_entry index[size];
public:
	int Hash_fun(int key)
	{
		int ind = key%size;
		return ind;
	}

	void insert_wor(int k , string value)
	{

		int hi = Hash_fun(k);
		int i = hi;
		bool flag = 0;


		while(i <=size )
		{
		if(index[i].key == -1)
		{
			index[i].key = k;
			index[i].val = value;
			break;
		}
		else
		{
			i++;
            if(i >size )
            {
                i = 0;
			    flag = 1;

				
            }
		}
		if(flag == 1 && i >hi)
		{
			cout << " Hash Table Overflow \n ";
			break;
		}

		
	    }

		
    }

	void insert_wr(int k, string value)
	{
		int hi = Hash_fun(k);
		int i = hi;

		while(i<size)
		{
			if(index[i].key == -1)
			{
				index[i].key = k;
				index[i].val = value;
				break;
			}

			else if( index[i].key != -1 &&  Hash_fun(index[hi].key) != hi)
			{
				while( index[i].key != -1)
				{
					i++;
					if(i>size)
					{
						i =0;
					}
				
				}
				
				index[i].key = index[hi].key;
				index[i].val = index[hi].val;

				index[hi].key = k;
				index[hi].val = value;
				

				break;
			}

			else
			{
				i++;
				if(i >size )
				{
					i = 0;

					
				}
			}

			


		}



		
	}

		void display()
		{
			for(int i =0; i<size;i++)
			{
				if(index[i].key == -1)
					continue;
				cout << i << " "<< index[i].key << " "<< index[i].val<<endl;
			}
		}
		void search(int k)
		{
			int hi = Hash_fun(k);
            int i = hi;
            int count = 1;
			bool flag = 0;
            while(i<= size)
            {
				if(index[i].key == k )
				{
					cout <<" Key is found after "<<count <<" comparisions \n ";
					break;
				}
				
                else
                {
					i++;
                    count++;
                    if(i > size )
                    {
                        i =0;
						flag =1;
                    }
                }

				if(flag == 1 && i> hi)
				{
					cout << " key is not found  \n ";
					break;
				}

            

            }

		}

};
int main()
{

	  HT obj;

   int n;

   int k ;
   string s;
   
char c='y';
while(c=='y')
{ 
cout<<"\n*********************************************\n";
cout<<" Hash Table \n ";
cout<<"*********************************************\n";
cout<<"Enter a Choice : "<<endl;
cout<<"1.  Insert without replacement  "<<endl;
cout<<"2.  Insert with replacement  "<<endl;
cout<<"3.  Disply     "<<endl;
cout<<"4.  Search   "<<endl;

cin>>n;
switch(n)
{
case 1:
	
	cout  << " Enter key  : ";
	cin >> k;
	cout << " Enter value : ";
	cin >>s;

	obj.insert_wor(k,s);


break;
case 2:
	
	cout  << " Enter key  : ";
	cin >> k;
	cout << " Enter value : ";
	cin >>s;

	obj.insert_wr(k,s);


break;
case 3:
               obj.display();
    break;
case 4: 
			
            cout<< " Enter key want to search : ";
			cin >> k;

			obj.search(k);

    break;



default: cout<<"Wrong choice input\n";
}
cout<<"\nDo you want to perform any other operation : (y/n)\n";
cin>>c;
}

    


	return 0;
}