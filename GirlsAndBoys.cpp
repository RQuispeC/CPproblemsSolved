#include<bits/stdc++.h>
#define INF 1e9
#define MAX 1510
using namespace std;
typedef vector < int > vi;
int n , m , NIL, tot, match[MAX], dist[MAX];
vector < vi > lista;
bool bfs()
{
	queue < int  > q;
	for(int i=0;i<n;i++)
		if(match[i]==NIL)
		{
			dist[i]=0;
			q.push(i);
		}
		else
			dist[i]=INF;
	dist[NIL]=INF;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(dist[match[v]]==INF)
			{
				dist[match[v]]=dist[u]+1;
				q.push(match[v]);
			}
		}
	}
	return dist[NIL] != INF;
}
bool dfs(int u)
{
	if(u!=NIL)
	{
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(dist[match[v]]==dist[u]+1)
			{
				if(dfs(match[v]))
				{
					match[u]=v;
					match[v]=u;
					return true;
				}
			}
		}
		dist[u]=INF;
		return false;
	}
	return true;
}
int hopcroft_karp()
{
	NIL=n+m;
	for(int i=0;i<n+m;i++)
		match[i]=NIL;
	int matching=0;
	//greedy
	for(int u=0;u<n;u++)
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(match[v]==NIL)
			{
				matching++;
				match[u]=v;
				match[v]=u;
				break;
			}
		}
		
	while(bfs())
	{
		for(int u=0;u<n;u++)
			if(match[u]==NIL && dfs(u))
				matching++; 
	}
	return matching;
}
vector < vi > tree;
int izq[MAX], der[MAX];
bool visited[MAX];
void dfs2(int u, bool flag) 
{
	visited[u]=true;
	flag==true? der[u]=n++:izq[u]=m++;// 0 --> der, 1 --> izq
	for(int i=0;i<tree[u].size();i++)
	{
		int v=tree[u][i];
		if(!visited[v])
			dfs2(v, not flag);
	}
}
void generate()
{
	for(int i=0;i<tot;i++)
	{
		visited[i]=0;
		der[i]=izq[i]=-1;
	}
	n=m=0;
	dfs2(0, true);
	for(int u=0;u<tot;u++)
	{
		if(der[u]!=-1) //pertenece a la derecha
		{
			for(int i=0;i<tree[u].size();i++)
			{
				int v=tree[u][i];
				lista[der[u]].push_back(izq[v]+n);
			}
		}
	}
}
int main()
{
	vi yyy;
	yyy.clear();
	while(cin>>tot)
	{
		lista.assign(MAX, yyy);
		tree.assign(MAX, yyy);
		for(int i=0;i<tot;i++)
		{
			int u,adj;
			char x,xx,xxx;
			scanf("%d%c %c%d%c",&u,&x,&xx,&adj,&xxx);
			for(int j=0;j<adj;j++)
			{
				int v;
				scanf("%d", &v);
				tree[u].push_back(v);
			}
		}
		generate();
		printf("%d\n", tot -hopcroft_karp());
	}	
}

