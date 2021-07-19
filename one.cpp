#include <bits/stdc++.h>
using namespace std;
# define N 1000000
vector<long long int> gr[N];
// Function to add edge
void add_edge(long long int x, long long int y)
{
    gr[x].push_back(y);
    gr[y].push_back(x);
}


int bfs(long long int source,long long int visited[])
{    
   long long int distance=1;
    queue<int> q;
    q.push(source);
    visited[source]=1;

    while(!q.empty())
    {
        long long int node=q.front();
        q.pop();
        for(long long int x: gr[node])
        {
            if(visited[x]==-1)
            {
                distance++;
                q.push(x);
                visited[x]=1;
            }

        }
    }
return distance;
}


int main()
{
long long int vertices,edges;
//cout<<"Enter the number of vertices and edges: "<<endl;
cin>>vertices>>edges;

for(int i=0;i<edges;i++)
{
    int x,y;
    //cout<<"Enter the graph: "<<endl;
    cin>>x>>y;
    add_edge(x,y);
}

long long int visited[vertices];

for(int i=0;i<vertices;i++)
{
    visited[i]=-1;
}

vector<long long int>count;

for(long long int i=0;i<vertices;i++)
{
    if(visited[i]==-1)
    {
        long long int dist=bfs(i,visited);
        count.push_back(dist);
    }
}


long long int total=0;
total=vertices*(vertices-1)/2;

for(long long int i=0;i<count.size();i++)
{
    total=total-(count[i]*(count[i]-1)/2);
}
cout<<total;
}
