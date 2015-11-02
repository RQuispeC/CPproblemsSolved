#include<bits/stdc++.h>
#define MAX 210
#define INF 1e9
using namespace std;
typedef vector < int  > vi;
int n, m, NIL, match[MAX], dist[MAX];
int der[MAX], izq[MAX];
vector < vi > lista;
bool bfs()
{
	queue < int > q;
	for(int i=0;i<n;i++)
		if(match[i]==NIL)
		{
			q.push(i);
			dist[i]=0;
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
			if(dist[match[v]] == dist[u]+1)
				if(dfs(match[v]))
				{
					match[v]=u;
					match[u]=v;
					return true;
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
		{
			if(match[u]==NIL && dfs(u))
				matching++;
		}
	}
	return matching;
}
int main()
{
	vi xxx;
	xxx.clear();
	int tested;
	scanf("%d", &tested);
	for(int t=1;t<=tested;t++)
	{
		lista.assign(MAX, xxx);
		int k=0;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%d", &der[i]);
		}		
		scanf("%d", &m);
		for(int i=0;i<m;i++)
		{
			scanf("%d", &izq[i]);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(der[i]!=0 && izq[j]%der[i]==0)
				{
					lista[i].push_back(j+n);
				}	
				else if(der[i]==0 && izq[j]==0)
					 {
						 lista[i].push_back(j+n);	
					 }
			}		 	
		printf("Case %d: %d\n",t, hopcroft_karp());	
	}
}

