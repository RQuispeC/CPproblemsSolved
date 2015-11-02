#include<bits/stdc++.h>
#define MAX 110
#define INF 1e9
using namespace std;
int parent[MAX];
int  n, m, mini ,maxi;
struct edge
{
	int u, v, weight;
	edge(){}
	edge(int a, int b, int w)
	{
		u=a;
		v=b;
		weight=w;
	}
	bool operator < (edge x) const
	{
		return weight<x.weight;
	}
};
edge incidencia[5000];
void ini(int li)
{
	for(int i=0;i<li;i++)
	{
		parent[i]=i;
	}	
}
int find(int x)
{
	if(parent[x]==x) 
		return x;
	return parent[x]=find(parent[x]);	
}
void Union(int x, int y)
{
	parent[find(x)]=find(y);
}
bool sol(int ind_ini)//krushkal
{
	ini(n);
	int tot=0;
	for(int i=ind_ini;i<m  ;i++)
	{
		int u=incidencia[i].u, v=incidencia[i].v;
		if(find(u) != find (v))
		{
			tot++;
			maxi=max(maxi, incidencia[i].weight);
			mini=min(mini, incidencia[i].weight);
			if(tot==n-1 ) 
				return 1;
			Union(u,v);	
		}
	}
	return 0;
}
int main()
{	
	while(cin>>n>>m)
	{
		if(n<=0 && m<=0 )  break;
		for(int i=0;i<m;i++)
		{
			int u, v ,w;
			scanf("%d %d %d", &u, &v ,&w);
			u--;v--;
			incidencia[i]=edge(u,v,w);
		}	
		sort(incidencia, incidencia+m);
		int ans=INF;
		for(int i=0;i<m;i++)
		{
			maxi=-INF; mini=INF;
			if(sol(i)  )
			{
				ans=min(ans, maxi- mini);	
			}
		}
		if(ans==INF)
			printf("%d\n", -1);
		else
			printf("%d\n", ans);
	}
}


