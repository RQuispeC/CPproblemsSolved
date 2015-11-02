#include<bits/stdc++.h>
#define MAX 10005
#define INF 1e9
#define SIZE 105
using namespace std;
string grip[SIZE];
int tot, n , m , NIL;
int col[SIZE][SIZE], fil[SIZE][SIZE];
vector < vector< int >  >  lista;
vector < int > visited;
int match[MAX], dist[MAX];
bool bfs()
{
	queue < int > q;
	for(int i=0;i<n;i++)
	{
		if(match[i]==NIL)
		{
			dist[i]=0;
			q.push(i);
		}
		else
			dist[i]=INF;	
	}
	dist[NIL]=INF;
	while(!q.empty())
	{
		int u=q.front();q.pop();
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
	return dist[NIL]!=INF;
}
bool dfs(int u)
{
	if(u!=NIL)
	{
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(dist[match[v]]==dist[u]+1)
				if(dfs(match[v]))
				{
					match[u]=v;
					match[v]=u;
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
				match[u]=v;
				match[v]=u;
				matching++;
				break;
			}
		}
	while(bfs())
	{
		for(int u=0;u<n;u++)
		{
			if(match[u]==NIL &&  dfs(u))
				matching++;
		}
	}
	return matching;	
}
int main()
{
	while(cin>>tot)
	{
		memset(col, -1, sizeof col);
		memset(fil, -1, sizeof fil);
		for(int i=0;i<tot;i++)
				cin>>grip[i];
				
		//filas
		n=0;		
		for(int i=0;i<tot;i++)
			for(int j=0;j<tot;j++)
			{
				if(grip[i][j]=='.')
				{
					while(j<tot && grip[i][j]=='.')
					{
						fil[i][j]=n;
						j++;
					}
					n++;	
				}	
			}
			
		//columnas	
		m=0;	
		for(int j=0;j<tot;j++)
			for(int i=0;i<tot;i++)
			{
				if(grip[i][j]=='.')
				{
					while(i<tot && grip[i][j]=='.')
					{
						col[i][j]=m;
						i++;
					}
					m++;	
				}	
			}
		lista.assign(MAX, vector < int > ());	
		for(int i=0;i<tot;i++)
			for(int j=0;j<tot;j++)
			{
				if(grip[i][j]=='.')
				{
					lista[fil[i][j]].push_back(col[i][j]+n);
				}
			}	
		printf("%d\n", hopcroft_karp());
	}
}
		
		
