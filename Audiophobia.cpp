#include<bits/stdc++.h>
#define MAX 110
using namespace std;
typedef pair < int , int  > pii;
typedef vector < pii  > vii;
int parent[MAX], rank[MAX], n, m,dist[MAX][MAX];
vector < vii > lista;
struct edge
{
	int u, v, w;
	edge(){}
	edge(int a, int  b, int c)
	{
		u=a, v=b, w=c;
	}
	bool operator < (edge x) const
	{
		return  w<x.w;
	}
};
void ini(int li)
{
	for(int i=0;i<li;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}
int find(int x)
{
	if(parent[x]==x) return x;
	return parent[x]=find(parent[x]);
}
void Union(int x, int y)
{
	int px=find(x), py=find(y);
	if(rank[px]>rank[py]) parent[py]=px;
	else
	{
		parent[px]=py;
		if(rank[px]==rank[py]) rank[py]++;
	}
}
edge incid[1010];
void krushkal()
{
	ini(n);
	sort(incid, incid+m);
	//for(int i=0;i<m;i++)
		//cout<<incid[i].u<<" "<<incid[i].v<<" * "<<incid[i].w<<endl;
	int tot=0;
	for(int i=0;i<m;i++)
	{
		if(find(incid[i].u) != find(incid[i].v))
		{
			//cout<<incid[i].u<<" -- "<<incid[i].v<<endl;
			lista[incid[i].u].push_back(pii(incid[i].v, incid[i].w));
			lista[incid[i].v].push_back(pii(incid[i].u, incid[i].w));
			tot++;
			if(tot==n-1)
				return;
			//cout<<"++"<<endl;	
			Union(incid[i].u, incid[i].v);
		}
	}
}
bool visited[MAX];
void dfs(int ini, int u, int lastMax)
{
	visited[u]=1;
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i].first, w=lista[u][i].second;
		if(!visited[v])
		{
			dist[ini][v]=dist[v][ini]=max(lastMax,w);
			dfs(ini, v, dist[ini][v]);
		}
	}
}
void precalc()
{
	for(int i=0;i<n;i++)
	{	
		memset(visited, 0, sizeof visited);
		dfs(i, i, 0);
	}	
}
int main()
{
	bool blank=0;
	int query, cas=1;
	while(scanf("%d %d %d", &n, &m, &query))
	{
		if(n==0 && m==0 && query==0) break;
		lista.assign(MAX, vii());
		if(blank) printf("\n"); blank=1;
		for(int i=0;i<m;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			//cout<<u<<" "<<v<<" "<<w<<endl;
			u--, v--;
			//cout<<w<<"  <--"<<endl;
			incid[i]=edge(u,v,w);
			//cout<<incid[i].u<<" "<<incid[i].v<<" * "<<incid[i].w<<endl;
		}
		krushkal();
		memset(dist, -1, sizeof dist);
		precalc();
		printf("Case #%d\n", cas++);
		for(int i=0;i<query;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--, v--;
			if(dist[u][v]!=-1)
				printf("%d\n", dist[u][v]);
			else
				printf("no path\n");	
		}
	}
}

