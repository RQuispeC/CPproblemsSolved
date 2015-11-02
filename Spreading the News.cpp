#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
//grafo dirigido
vector < vector < int > > lista;
bool visited [2510];
int MAXday, per, n;
void bfs(int ini)
{
	memset(visited, false, sizeof visited);
	int t, acu=0, temp=1;
	queue < int  > cola;
	cola.push(ini);
	int day=0;
	per=0;
	visited[ini]=true;
	while(!cola.empty())
	{
		t=cola.front();
		cola.pop();
		int contNext=0;
		for(int i=0;i<lista[t].size();i++)
		{
			if(!visited[lista[t][i]])
			{
				visited[lista[t][i]]=true;
				contNext++;
				cola.push(lista[t][i]);
			}
		}
		acu+=contNext;
		temp--;
		if(temp==0)// termino un dia
		{
			day++;
			temp=acu;
			if(per<acu)//primera vez del MAXIMO
			{
				per=acu;
				MAXday=day;				
			}
			//cout<<day<<" :  "<<per<<endl;
			acu=0;
		}
		
	}
	if(per!=0)
		printf("%d %d\n", per, MAXday);
	else
		printf("%d\n", 0);
} 
int main()
{
	vector < int > aux;
	aux.clear();
	lista.clear();
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		lista.push_back(aux);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d", &num);
		for(int j=0;j<num;j++)
		{
			int v;
			scanf("%d", &v);
			lista[i].push_back(v);
		}
	}
	int tested;
	scanf("%d",&tested);
	for(int i=0;i<tested;i++)
	{
		int ini;
		scanf("%d", &ini);
		bfs(ini);
	}
	
}

