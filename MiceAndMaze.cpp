#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define INF 1000000000
#define MAX 105
using namespace std;
struct node
{
	int ver, weight;
	node(){}
	node(int v, int w)
	{
		ver=v;
		weight=w;
	}
	bool operator < (node x) const
	{
		return weight > x.weight;
	}
};
vector < vector < node > >  lista;
bool visited [MAX];
vector < int > dist ;
int n;
int ans;
void dijkstra(int ini)
{
	memset(visited, false, sizeof visited);
	priority_queue < node > cola;
	cola.push(node(ini, 0));
	dist[ini]=0;
	while(!cola.empty())
	{
		node aux=cola.top();
		cola.pop();
		int t=aux.ver;
		visited[t]=true;
		for(int i=0;i<lista[t].size();i++)
		{
			if(!visited[lista[t][i].ver] )
			{
				if(dist[lista[t][i].ver]>aux.weight+lista[t][i].weight)
				{	
					dist[lista[t][i].ver]=aux.weight+lista[t][i].weight;
					cola.push(lista[t][i]);					
				}
			}
		}
	}	
}
int main()
{
	vector < node > help;
	help.clear();
	int tested;
	scanf("%d", &tested);
	bool blank=false;
	while(tested--)
	{
		if(blank) printf("\n");
		blank=true;
		ans=0;
		lista.clear();
		dist.clear();
		int time,exit,m;
		cin>>n>>exit>>time>>m;
		//scanf("%d %d %d %d", &n, &exit, &time, &m);
		for(int i=0;i<n;i++)
		{
			lista.push_back(help);
			dist.push_back(INF);
		}
		for(int i=0;i<m;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			lista[u-1].push_back(node(v-1, w));
		}
		dijkstra(exit-1);
		for(int i=0;i<n;i++)
			if(dist[i]<=time) ans++;
		printf("%d\n", ans);
	}
}

