#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define INF 1000000000
using namespace std;
struct nodo
{
	int weight;
	int v;
	nodo()
	{}
	nodo(int ver , int we)
	{
		weight=we;
		v=ver;
	}
	bool operator < (nodo x) const
	{
		return weight>x.weight;
	}
};
vector < vector < nodo > > lista;
bool visited [20010];
vector < int > dist;
int n,m,s, t;
void dijkstra( int ini)
{
	priority_queue < nodo > cola;
	dist[ini]=0;
	cola.push( nodo ( ini, 0));
	while(!cola.empty())
	{
		nodo aux =cola.top();
		int t=aux.v;
		visited[t]=true;
		cola.pop();
		//cout<<" * "<<t<<endl;
		for(int i=0;i<lista[t].size();i++)
		{
			int vecino=lista[t][i].v; //vecino i de T
			int distVecino=lista[t][i].weight; //distancia de i a T
			//cout<<" ** "<<vecino<<endl;
			if(!visited[vecino]  )
			{
				//cout<<dist[vecino]<<"  :  "<<dist[t]+distVecino<<endl;
				if(dist[vecino]>dist[t]+distVecino)
				{
					dist[vecino]=dist[t] + distVecino;
					cola.push( nodo ( vecino, dist[vecino]));
				}
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
			int u,v, w;
			scanf("%d %d %d", &u, &v , &w);
			lista[u].push_back(nodo(v, w));
			lista[v].push_back(nodo(u, w));
		} 
		dijkstra(s);
		cout<<"Case #"<<te<<": ";
		if(dist[t]!=INF) 
			printf("%d\n", dist[t]);
		else
			printf("unreachable\n");	
	}
} 

