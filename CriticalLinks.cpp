#include<bits/stdc++.h>
#define MAX 100000
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
				puentes.push_back(pii(min(u,v),max(u,v)));
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
	bool f=0;
	int n;
	while(cin>>n)
	{
		if(f) cout<<endl; f=1;
		lista.assign(n, vi());
		puentes.clear();
		dfsCounter=0; 
		memset(dfs_num, -1, sizeof dfs_num);
		memset(dfs_low, 0, sizeof dfs_low);
		memset(dfs_parent, -1, sizeof dfs_parent);
		memset(articulation_point, 0, sizeof articulation_point);
		for(int i=0;i<n;i++)
		{
			int u, cont;
			scanf("%d (%d)", &u, &cont);
			for(int j=0;j<cont;j++)
			{
				int v;
				scanf("%d", &v);
				lista[u].push_back(v);
			}
		}
		for(int i=0;i<n;i++)
			if(dfs_num[i]==-1)
			{
				dfsRoot = i; rootChildren = 0;
				Puntos_Puentes(i);
				articulation_point[dfsRoot] = (rootChildren > 1);// special case 
			}
		sort(puentes.begin(), puentes.end());
		printf("%d critical links\n", (int)puentes.size());
  		for (int i = 0; i < puentes.size(); i++)
			printf("%d - %d\n", puentes[i].first, puentes[i].second);
	}
}

