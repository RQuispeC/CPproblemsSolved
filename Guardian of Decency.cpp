#include<bits/stdc++.h>
#define MAX 1010
#define INF 1e9
using namespace std;
/*
0..n-1  derecha
n..m-1  izquierda
NIL: nodo n+m	
*/
struct node
{
	int hight;
	string music, sport;
	node(){}
	node( int a, string c, string d)
	{
		hight=a;
		music=c, sport=d;
	}
};
int n , m , NIL, tot, match[MAX], dist[MAX];
vector < vector < int  > > lista;
bool posible( node x, node y)
{
	
	return abs(x.hight - y.hight) <= 40  && x.music == y.music && x.sport != y.sport;
}
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
		int u=q.front(); q.pop();
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(dist[match[v]] == INF)
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
	if (u!=NIL)
	{
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i];
			if(dist[match[v]] == dist [u] +1 )
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
	{
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
	node  male [MAX];
	node  female [MAX];
	vector < int > xxx;
	xxx.clear();	
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{	
		lista.assign(MAX, xxx);
		scanf("%d", &tot);
		n=0;m=0;
		for(int i=0;i<tot;i++)
		{
			int hi;
			char se;
			string mu,sp;
			cin>>hi>>se>>mu>>sp;
			if(se=='F')
			{
				female[m]=node(hi, mu, sp);
				m++;
			}
			else
			{
				male[n]=node(hi, mu, sp);
				n++;
			}
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(posible(male[i], female[j]))
					lista[i].push_back(j+n);
		cout<<tot-hopcroft_karp()<<endl;	
		
	}
}
