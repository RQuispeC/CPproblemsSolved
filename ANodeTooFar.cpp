#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int NC, n , ttl;
vector < vector < int > > lista ;
bool visited [35];
map < int , int > mapa;
vector < int > nodes;
void bfs( int nodoIni)
{
	int t,acu=0, temp=1;
	queue < int > cola;
	cola.push(nodoIni);
	visited[nodoIni]=true;
	while(!cola.empty())
	{
		int contNext;
		t=cola.front();
		cola.pop();
		contNext=0;
		for(int i=0;i<lista[t].size();i++)
		{
			if(!visited[lista[t][i]] && ttl>0)
			{
				visited[ lista[t][i]]=true;
				cola.push(lista[t][i]);
				contNext++;			
			}		
		}
		acu+=contNext;
		temp--;
		if(temp==0)
		{
			ttl--;
			temp=acu;
			acu=0;
		}
	} 
}
int main()
{
	vector < int > aux;
	aux.clear();
	int testCase=1;
	while(cin>>NC)
	{
		if(NC<=0) break;
		mapa.clear();
		lista.clear();
		nodes.clear();
		for( int i=0;i<35;i++)//incializar lista de adyacencia
		{
			lista.push_back( aux ); 
		}
		int k=1;
		for(int i=0;i<NC;i++)
		{
			int u,v;
			scanf("%d %d", &u,&v );
			if( mapa[u]==0 )// first time
			{
			 	mapa[u]=k++;
			 	nodes.push_back(u);			 	
			}
			if( mapa[v]==0 )// first time
			{
			 	mapa[v]=k++;		
			 	nodes.push_back(v);	 	
			}
			lista[mapa[u]].push_back(mapa[v]);
			lista[mapa[v]].push_back(mapa[u]);
		}
		n=nodes.size();
		int nodIni;
		while(cin>>nodIni>>ttl)
		{
			int aux=ttl;
			if(nodIni==0 && ttl==0) break;
			memset( visited , false, sizeof visited );
			bfs( mapa[nodIni] );
			int ans=0;
			for(int i=1;i<=n;i++)
				if(!visited[i]) ans++;
			cout<<"Case "<<testCase++<<": "<<ans<<" nodes not reachable from node "<<nodIni<<" with TTL = "<<aux<<"."<<endl;
		}	
		
		
	}
}

