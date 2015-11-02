#include<bits/stdc++.h>
#define MAX 210
#define INF 1e9
using namespace std;
int parent[MAX];
int begin  ,end, n, m;
struct edge
{
	int u, v, weight;
	edge(){}
	edge(int a, int b, int w)
	{
		u=a;
		v=b;
		weight=w;
	}
	bool operator < (edge x) const
	{
		return weight<x.weight;
	}
};
edge incidencia[1010];
void ini(int li)
{
	for(int i=0;i<li;i++)
	{
		parent[i]=i;
	}	
}
int find(int x)
{
	if(parent[x]==x) 
		return x;
	return parent[x]=find(parent[x]);	
}
void Union(int x, int y)
{
	parent[find(x)]=find(y);
}
int sol2(int min_w){
    ini(n);
    for(int i = 0;i<m;i++)
    {
        if(incidencia[i].weight>=min_w)
        {
            Union(incidencia[i].u,incidencia[i].v);
            if(find(begin)==find(end)) return incidencia[i].weight;
        }
    }
    return -1;
}

int sol()
{
    int ret = -1;
    for(int i = 0, x ;i<m;i++)
    {
        x = sol2(incidencia[i].weight);
        if(x!=-1)
        {
            if(ret==-1) ret = x-incidencia[i].weight;
            else ret = min(ret,x-incidencia[i].weight);
        }
    }
    
    return ret;
}
int main()
{	
	while(cin>>n>>m)
	{
		if(n<=0 && m<=0 )  break;
		for(int i=0;i<m;i++)
		{
			int u, v ,w;
			scanf("%d %d %d", &u, &v ,&w);
			u--;v--;
			incidencia[i]=edge(u,v,w);
		}
		scanf("%d %d", &begin, &end);
		begin--;end--;
		sort(incidencia, incidencia+m);
		printf("%d\n", sol());	
	}
}
/*
5 5
1 2 100
2 3 101
3 4 102
1 5 20
5 4 80
1 4
16 21
1 2 50
2 3 50
3 6 100
6 7 80
7 8 20
8 11 10
11 16 100
1 4 50
4 2 100
4 5 150
5 3 110
5 12 200
12 13 150
13 14 50
14 15 50
15 16 200
14 11 200
13 9 10
6 9 20
9 10 80
10 11 50
1 16 
3 2
1 2 100
1 2 1000
1 3
0 0
*/

