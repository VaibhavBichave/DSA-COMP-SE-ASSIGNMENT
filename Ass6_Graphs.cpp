#include<bits/stdc++.h> 
using namespace std;

class node
{
	string data;
	node* next;
	int index;

public:
	node(string n, int i)
	{
		data =n;
		index = i;
		next = NULL;
	}

	friend class Graph;
};

class Graph
{
	node** list;
	int var;
public:

	Graph(int v);
	void create_graph();
	void add_edge(string src, string dest);
	void display();
	void bfs(int i );
	void dfs(int i);

};

Graph :: Graph(int v)
	{
		var =v;
		list = new node*[var];
		for(int i =0; i<var; i++)
		{
			list[i] = NULL;
		}
	}

void Graph :: create_graph()
	{
		string s;
		for(int i = 0; i<var;i++)
		{
			cout << " Enter landmark "<< i<< endl;
			cin >>s;
			node* temp = new node(s ,i);
			list[i] = temp;
		}

	}


void Graph :: add_edge(string src, string dest)
	{
		int ind ;
		for(int i = 0;i<var;i++)
		{
			if (list[i]->data == dest)
			{
				ind  = i;
				break;
			}
			

		}
		node* temp = new node(dest, ind);
		for(int i =0; i<var;i++)
		{
			if(list[i]->data == src)
			{
				if(list[i]->next == NULL)
				{
					list[i]->next = temp;
					break;
				}
				else
				{
					node* ptr = list[i];
					while(ptr->next != NULL)
					{
						ptr = ptr->next;
					}
					ptr->next = temp;
					break;
				}
			}
		}
	}

void  Graph :: display()
	{
		for(int i =0; i<var; i++)
		{
			node* temp = list[i];
			while(temp->next )
			{
				cout << temp->data<<" -> ";
				temp = temp->next;
			}
			cout << temp->data<<endl;
		
		}
	}

void Graph :: bfs(int i )
	{
		int visited[var];
		for(int i =0; i<var; i++)
		{
			visited[i] =0;	
		}
		queue<int> Q;
		Q.push(i);
		visited[i] = 1;
		while(!Q.empty())
		{
			cout << list[Q.front()]->data << " ";
			node* temp = list[Q.front()];
			Q.pop();
		
			while (temp != NULL)
			{
				if(visited[temp->index] == 0)
				{
					Q.push(temp->index);
					visited[temp->index] = 1;
				}
				temp = temp->next;
			}
		}
	}

void Graph :: dfs(int i)
	{
		int visited[var];

		for(int i =0; i<var; i++)
		{
			visited[i] = 0;
		}

		stack<int> s;
		s.push(i);
		visited[i] = 1;
		while(!s.empty())
		{
			int t  = s.top();
			
			s.pop();
			cout <<list[t]->data<<" ";

			node* temp = list[t];
			while(temp != NULL)
			{
				if(visited[temp->index] == 0)
				{
					s.push(temp->index);
					visited[temp->index] = 1;
				}
				temp = temp->next;
			}
		}
	}

int main(){
	Graph obj(6);

	obj.create_graph();

	obj.add_edge("a", "b");
	obj.add_edge("a", "c");
	obj.add_edge("a", "d");
	obj.add_edge("b", "d");
	obj.add_edge("c", "d");
	obj.add_edge("c", "e");
	obj.add_edge("d", "f");
	obj.add_edge("e", "f");
	obj.display();


	obj.bfs(0);
	cout <<endl;
	obj.dfs(1);
	return 0;
}