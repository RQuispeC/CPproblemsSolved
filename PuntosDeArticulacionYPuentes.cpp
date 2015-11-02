#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
vector < vi > lista;
bool articulation_point[MAX];
vector < pii >  puentes;
int dfs_low[MAX], dfs_num[MAX], dfsCounter, dfsRoot, dfs_parent[MAX], rootChildren;
void Puntos_Puentes(int u)
{
	dfs_low[u]=dfs_num[u]=dfsCounter++;
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		if(dfs_num[v]==-1) // tree edge
		{ 
			dfs_parent[v]=u;
			if(u == dfsRoot) rootChildren++; // caso especial, cuenta el hijo de root
			Puntos_Puentes(v);
		
			if(dfs_low[v]>=dfs_num[u]) //puntos
				articulation_point[u]=true;
			if(dfs_low[v]> dfs_num[u]) //puentes
				puentes.push_back(pii(u,v));
			dfs_low[u]=min(dfs_low[u], dfs_low[v]);
		}
		else
		{
			if(v != dfs_parent[u]) // un back edge y ciclo no directo
				dfs_low[u]=min(dfs_low[u], dfs_low[v]);
		}
	}
}
int main()
{
	lista.assign(MAX, vi());
	puentes.clear();
	dfsCounter=0; 
	memset(dfs_num, -1, sizeof dfs_num);
	memset(dfs_low, 0, sizeof dfs_low);
	memset(dfs_parent, -1, sizeof dfs_parent);
	memset(articulation_point, 0, sizeof articulation_point);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		int total_neighbors;
    	scanf("%d", &total_neighbors);
    	for (int j = 0; j < total_neighbors; j++) 
    	{
    		int v;
      		scanf("%d", &v);
      		lista[i].push_back(v);
    	}
  	}

	for (int i = 0; i < n; i++)
		if (dfs_num[i] == -1) 
		{
			dfsRoot = i; rootChildren = 0;
			Puntos_Puentes(i);
			articulation_point[dfsRoot] = (rootChildren > 1);// special case 
		} 
  	printf("Articulation Points:\n");
  	for (int i = 0; i < n; i++)
    	if (articulation_point[i])
      	printf("node :  %d\n", i);
    printf("Bridges:\n");
  	for (int i = 0; i < puentes.size(); i++)
		printf("%d : %d \n", puentes[i].first, puentes[i].second);	
}
/*
8
1 1
1 3
1 1
2 2 4
1 5
1 7
1 4
1 6
*/


