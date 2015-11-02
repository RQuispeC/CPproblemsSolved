#include<bits/stdc++.h>
#define MAX 210  
#define INF 1e9
using namespace std;
int p[MAX];
int adj[MAX][MAX];
void ini (int li)
{
	for(int i=1;i<=li;i++)
		p[i]=i;
}
int find(int x)
{
	if(p[x]==x) return x;
	return p[x]=find(p[x]);
}
void Union(int x, int y)
{
	p[find(x)]=find(y);
}	
struct edge
{
	int u, v, weight;
	edge(){}
	edge(int a, int b, int w)
	{
		u=a,v=b,weight=w;
	}
	bool operator <(edge x) const
	{
		return weight > x.weight;
	}
};
edge inci[100000];
int n , m;
void kru()
{
	ini(n);
	sort(inci, inci+m);
	int tot=0;
	for(int i=0;i<m;i++)
	{
		if(find(inci[i].u) != find(inci[i].v))
		{
			tot++;
			adj[inci[i].u][inci[i].v]=adj[inci[i].v][inci[i].u]=inci[i].weight;
			if(tot==n-1)
				return;
			Union(inci[i].u, inci[i].v);
		}
	}
	return;
}
bool visited[MAX];
int ans, s, t;
bool dfs(int node)
{
	if(node==t)
		return 1;
	visited[node]=1;
	for(int i=1;i<=n;i++)
	{
		if(adj[node][i]>0 && !visited[i])
			if(dfs(i))
			{
				ans=min(ans, adj[node][i]);
				return 1;
			}	
	}
	return 0;	
}
int main()
{
	vector <  int  > xxx;
	xxx.clear();
	map < string  , int > mapa;
	int sce=1;
	while(scanf("%d %d", &n , &m))
	{
		if(n<=0 && m<=0 )  break;
		mapa.clear();
		int k=1;
		for(int i=0;i<m;i++)
		{
			string a, b;
			int w;
			cin>>a>>b>>w;
			if(mapa[a]==0)
				mapa[a]=k++;
			if(mapa[b]==0)
				mapa[b]=k++;		
			int pa=mapa[a], pb=mapa[b];	
			inci[i]=edge(pa, pb, w);
		}
		string a, b;
		cin>>a>>b;
		if(mapa[a]==0)
			mapa[a]=k++;
		if(mapa[b]==0)
			mapa[b]=k++;
		s=mapa[a], t=mapa[b];
		memset(adj, 0, sizeof adj); 
		kru();
		memset(visited, 0, sizeof visited);
		ans=INF;
		dfs(s);
		cout<<"Scenario #"<<sce++<<endl;
		cout<<ans<<" tons"<<endl<<endl;
	}
}

