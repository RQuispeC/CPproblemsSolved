#include<bits/stdc++.h>
#define MAX 110
using namespace std;
typedef vector < int >   vi;
vector < vi > lista;
vi toposort;
bool visited[MAX];
void dfs(int u)
{
	visited[u]=1;
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		if(!visited[v])
			dfs(v);
	}
	toposort.push_back(u);
}
int main()
{
	int n , m;
	while(scanf("%d %d", &n ,&m))
	{
		if(n<=0 && m<=0 )  break;
		lista.assign(MAX, vi());
		toposort.clear();
		memset(visited, false, sizeof visited);
		for(int i=0;i<m;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v) ;
			u--;v--;
			lista[u].push_back(v);
		}
		for(int i=0;i<n;i++)
			if(!visited[i])
				dfs(i);
		reverse(toposort.begin(), toposort.end());
		for(int i=0;i<n;i++)
		{
			cout<<toposort[i]+1;
			if(i+1<n) cout<<" ";
		}
		cout<<endl;
	}
}

