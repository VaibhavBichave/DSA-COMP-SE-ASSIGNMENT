#include <iostream>
using namespace std;

class Graph
{
    int no_vertex;
    int no_edges;
    int ** adj_mat;
    public:
    Graph()
    {
        no_vertex=0;
        no_edges=0;
        adj_mat=new int*[0];
    }
    Graph(int v,int e)
    {
        no_vertex=v;
        no_edges=e;
        adj_mat=new int*[v];
        for(int i=0;i<v;i++)
        {
            adj_mat[i]=new int[v];
        }
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                adj_mat[i][j]=-1;
            }
        }
    }

    void accept_graph()
    {
        int s,d;
        for(int i=0;i<no_edges;i++)
        {
            cout<<"Enter the source vertex : ";
            cin>>s;
            cout<<"Enter the destination vertex : ";
            cin>>d;
            add_edge(s,d);
        }

    }

    void add_edge(int s,int d)
    {
        int w;
        cout<<"Enter weight : ";
        cin>>w;
        adj_mat[s][d]=w;
        adj_mat[d][s]=w;
        }

    void display()
    {
        for(int i=0;i<no_vertex;i++)
        {
            for(int j=0;j<no_vertex;j++)
            {
                cout<<adj_mat[i][j]<<"  |  ";
            }
            cout<<endl;
        }

    }
};

int main()
{
int ch;
int x,y;
int start;
cout<<"Enter the number of vertices : ";
cin>>x;
cout<<"Enter the number of edges : ";
cin>>y;
Graph g1(x,y);
while(true)
{
cout<<"\n**********MENU*********"<<endl;
cout<<"1.Create Graph\n2.Display Graph\n3.\n4.\n5.Exit\n";
cout<<"Enter choice :";
cin>>ch;

switch(ch)
{
case 1:
    g1.accept_graph();
    break;
case 2:
    g1.display();
    break;
case 3:
    
    break;
case 4:
    
    break;
case 5:
    cout<<"exiting....";
    exit(1);
    break;
default:
    cout<<"Invalid choice !"<<endl;
}
}
}
