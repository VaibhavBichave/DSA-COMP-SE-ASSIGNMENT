
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int dest;
	Node *next;

	Node()
	{
		dest = 0;
		next = NULL;
	}
	Node(int d)
	{
		dest = d;
		next = NULL;
	}
};

class Graph
{
	int n;
	Node **adjList;
	bool *visited;
	string *landmarks;
public:
	Graph(int n);
	~Graph();
	void showLandmarks();
	void addEdge(int s, int d);
	void push(int source, int destination);
	void showList();
	void bfs(int start);
	void dfs(int start);
};

Graph::Graph(int n)
{
	this->n = n;
	adjList = new Node *[n];
	landmarks = new string [n];
	for (int i = 0; i < n; i++)
	{
		string s;
		cout << "Enter landmark " << i << " : "; 
		cin >> s;
		landmarks[i] = s;

		adjList[i] = NULL;
	}

	visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	cout << "Graph with no edges created" << endl;
}

Graph::~Graph()
{
	delete[] adjList;
	delete[] visited;
}

void Graph::push(int source, int destination)
{
	Node *newNode = new Node(destination);
	Node *ptr = adjList[source];

	if (ptr == NULL)
	{
		adjList[source] = newNode;
		return;
	}

	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = newNode;
}



void Graph::addEdge(int source, int destination)
{
	push(source, destination);
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
}

void Graph::showLandmarks()
{
	cout << endl;
	for(int i =0; i < n; i++)
	{
		cout << i << ". " << landmarks[i] << endl;
	}
}

void Graph::showList()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << landmarks[i] << ": ";
		Node *temp = adjList[i];

		if (adjList[i] == NULL)
		{
            
			cout << endl;
			continue;
		}

		while (temp->next != NULL)
		{
			cout << landmarks[temp->dest] << " -> ";
			temp = temp->next;
		}
		cout << landmarks[temp->dest] << " ";

		cout << endl;
	}
}

void Graph::bfs(int start)
{
	bool visited[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	queue<int> Q;

	Q.push(start);
	cout << "BFS: ";
	while (!Q.empty())
	{
		int u = Q.front();

		cout << landmarks[u] << " ";
		visited[u] = true;
		Q.pop();

		for (auto i = adjList[u]; i != NULL; i = i->next)
		{
			if (!visited[i->dest])
			{
				visited[i->dest] = true;
				Q.push(i->dest);
			}
		}
	}

	cout << endl;
}

void Graph::dfs(int start)
{
	visited[start] = true;

	cout << landmarks[start] << " ";
	for (auto itr = adjList[start]; itr != NULL; itr = itr->next)
	{
		if (!visited[itr->dest])
			dfs(itr->dest);
	}
}

int main()
{

	cout << "Enter number of nodes: ";
	int n;
	cin >> n;
	Graph nearbyMap(n);

	while (true)
	{

		cout << "\n----MAIN MENU----\n";
		cout << "1. AddEdge\n";
		cout << "2. View Adj List\n";
		cout << "3. BFS\n";
		cout << "4. DFS\n";
		cout << "5. Exit\n";

		string choice;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == "1")
		{
			int s, d;
			nearbyMap.showLandmarks();
			cout << "Enter the source vertex: ";
			cin >> s;
			cout << "Enter the destination vertex: ";
			cin >> d;
			if (s > n || d > n)
			{
				cout << "Enter valid vertex" << endl;
				continue;
			}
			nearbyMap.addEdge(s, d);
		}
		else if (choice == "2")
		{
			nearbyMap.showList();
		}
		else if (choice == "3")
		{
			cout << "Enter starting point: ";
			int start;
			nearbyMap.showLandmarks();
			cin >> start;

			if (start > n)
			{
				cout << "Enter valid vertex" << endl;
				continue;
			}
			nearbyMap.bfs(start);
		}
		else if (choice == "4")
		{
			cout << "Enter starting point: ";
			int start;
			nearbyMap.showLandmarks();
			cin >> start;

			if (start > n)
			{
				cout << "Enter valid vertex" << endl;
				continue;
			}
			cout << "DFS: ";
			nearbyMap.dfs(start);
			cout << endl;
		}
		else if (choice == "5")
		{
			cout << "Exited successfully" << endl;
			break;
		}
	}

	return 0;
}