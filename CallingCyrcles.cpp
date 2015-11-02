#include<bits/stdc++.h>
#define MAX 30
using namespace std;
typedef vector < int  > vi;
int n, m,dfsCont,dfs_num[MAX], dfs_low[MAX];
vector < vi > lista;
string ans[MAX];
vi pila;
map < string , int > names;
bool visited[MAX];
void tarjan(int u)
{
	dfs_low[u]=dfs_num[u]=dfsCont++;
	visited[u]=1;
	pila.push_back(u);
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		if(dfs_num[v]==-1)
			tarjan(v);
		if(visited[v])	
			dfs_low[u]=min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u]==dfs_num[u])
	{
		while(true)
		{
			int v=pila.back();
			pila.pop_back();
			visited[v]=0;
			cout<<ans[v];
			if(u==v) break;
			cout<<", ";
		}
		printf("\n");
	}
}
int main()
{
	int t=1;
	bool blank=0;
	while(scanf("%d %d", &n , &m), n, m)
	{
		if(blank) cout<<endl;
		blank=1;
		printf("Calling circles for data set %d:\n", t++);
		names.clear();
		pila.clear();
		lista.assign(MAX, vi());
		memset(dfs_low, 0, sizeof dfs_low);
		memset(dfs_num, -1, sizeof dfs_num);
		memset(visited, 0, sizeof visited);
		dfsCont=0;
		int k=1;
		for(int i=0;i<m;i++)
		{
			string a,b;
			cin>>a>>b;
			if(names[a]==0)
			{
				ans[k]=a;
				names[a]=k++;
			}	
			if(names[b]==0)
			{
				ans[k]=b;
				names[b]=k++;
			}	
			lista[names[a]].push_back(names[b]);
		}
		k=1;
		for(int i=1;i<=n;i++)
			if(dfs_num[i]==-1)
				tarjan(i);	
	}
}


