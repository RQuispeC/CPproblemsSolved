#include<bits/stdc++.h>
#define MAX 100010
using namespace std;
typedef vector < int > vi;
vector < vi > lista, trans;
vi  pila, caidos;
bool visited[MAX];
int n,m, dfsCount, numComp, ans, dfs_num[MAX], dfs_low[MAX],comp[MAX] ;
void ini(int li)
{
	ans=li;
	for(int i=0;i<li;i++)
		dfs_num[i]=-1, dfs_low[i]=visited[i]=0, comp[i]=i;
}
void tarjan(int u)
{
	dfs_num[u]=dfs_low[u]=dfsCount++;
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
		while(1)
		{
			int v=pila.back();
			pila.pop_back();
			visited[v]=0;
			comp[v]=numComp;
			if(v==u)  break;
		}
		numComp++;
	}
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		pila.clear();
		dfsCount=numComp=0;
		
		scanf("%d %d", &n, &m);
		ini(n);
		lista.assign(n, vi());
		trans.assign(n, vi());
		for(int i=0;i<m;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--,v--;
			lista[u].push_back(v);
			trans[v].push_back(u);
		}
		for(int i=0;i<n;i++)
			if(dfs_num[i]==-1)
				tarjan(i);	
		ans=numComp;
		caidos.assign(numComp, 0);
		for(int u=0;u<n;u++)
			if(!caidos[comp[u]])
				for(int j=0;j<trans[u].size();j++)
				{
					int v=trans[u][j];	
					if(comp[v] != comp[u])
					{
						caidos[comp[u]]=1;
						ans--;
						break;
					}
				}				
		printf("%d\n", ans);
	}		
}

