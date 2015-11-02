#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define INF 100000000000ll
using namespace std;
struct nodo
{
	long long weight;
	int v;
	nodo()
	{
		weight=-1;
		v=-1;
	}
	nodo(int ver , long long weight)
	{
		weight=w;
		v=ver;
	}
	bool operator (nodo x) const
	{
		return weight>x.weight;
	}
};
vector < vector < nodo > > lista;
bool visited [20010];
vector < long long > dist;
int n,m,s, t;
void dijkstra( int ini)
{
	priority_queue < nodo > cola;
	dist[ini]=0ll;
	cola.push( nodo ( 0ll, ini));
	while(!cola.empty())
	{
		nodo aux =cola.top();
		int t=aux.v;
		visited[t]=true;
		cola.pop();
		for(int i=0;i<lista[t].size();i++)
		{
			int vecino=lista[t][i].v; //vecino i de T
			long long distVecino=lista[t][i].weight; //distancia de i a T
			if(!visited[vecino]  )
			{
				dist[vecino]=min(dist[vecino], dist[t] + distVecino);
				cola.push( nodo ( dist[vecino], vecino));
			}
		}
	}
}
int main()
{
	vector < nodo > aux;
	aux.clear();
	int tested;
	scanf("%d", &tested);
	for(int te=1;te<=tested;te++)
	{
		lista.clear();
		dist.clear();
		memset(visited, false, sizeof visited);
		scanf("%d %d %d %d", &n, &m, &s, &t);
		for(int i=0;i<n;i++)//inicializar
		{
			dist.push_back(INF);
			lista.push_back(aux);
		}
		for(int i=0;i<m;i++)
		{
			int u,v;
			long long w;
			cin>>u>>v>>w;
			lista[u].push_back(nodo(v, w));
			lista[v].push_back(nodo(u, w));
		}
		dijkstra(s);
		cout<<"Case #"<<te<<": ";
		if(dist[t]!=INF) 
			cout<<dist[t]<<endl;
		else
			cout<<"unreachable"<<endl;	
	}
} 

