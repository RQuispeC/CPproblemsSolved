#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
int n, m, s, t, K;
vector < int >  a [MAX]; 
vector < int > k;
vector < int > topo;
bool visited [MAX];
void dfs( int node)
{
	visited [node] =1;
	for(int i=0;i<a[node].size();i++)
	{
		if(!visited[a[node][i]])
			dfs(a[node][i]);
	}
	topo.push_back(node);
}
int  numPaths( int x, int y)
{
	
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		k.clear();
		topo.clear();
		memset(visited, 0, sizeof visited);
		for(int i=0;i<n;i++)
			a[i].clear();
		scanf("%d %d",&n , &m );
		for(int i=0;i<m;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
		}
		scanf("%d %d %d", &s, &t, &K);
		for(int i=0;i<K;i++)
		{	
			int v;
			scanf("%d ", &v);
			k.push_back(v);				
		}
		dfs(s);
		reverse(topo.begin(), topo.end());
		for(int i=0;i<n;i++)
			cout<<topo[i]<<"  ";  
		cout<<endl;
		cout<<"-------------"<<endl;	
	}
}

