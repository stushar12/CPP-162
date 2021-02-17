#include <bits/stdc++.h>
using namespace std;
# define N 1000000
vector<long long int> gr[N];
// Function to add edge
void Add_edge(long long int x, long long int y)
{
	gr[x].push_back(y);
    gr[y].push_back(x);
}


long long int DFS(long long int source,long long int visited[],long long int connected)
{
visited[source]=1;
for(auto x: gr[source])
{
    if(visited[x]==0)
    {
        connected++;
        connected=DFS(x,visited,connected);
    }
}
return connected;
}


int main()
{
long long int n;
cout<<"\nEnter the number of nodes: ";
cin>>n;
long long int pairs;
cout<<"\nEnter the number of pairs: ";
cin>>pairs;
cout<<"\nEnter the pairs:\n";
for(long long int i=0;i<pairs;i++)
{
    long long int x,y;
    cin>>x>>y;
    Add_edge(x,y);
}

long long int visited[n]={0};
long long int connected_components=1;
long long int connected[n]={0};
long long int count=0;
for(long long int i=0;i<n;i++)
{
    if(visited[i]==0)
    {
        long long int x=DFS(i,visited,connected_components);
        connected[count]=x;
        count++;
    }
}

long long int total=n*(n-1)/2;

for(long long int i=0;i<count;i++)
{
	total=total-(connected[i]*(connected[i]-1)/2);
}

cout<<total;
}
