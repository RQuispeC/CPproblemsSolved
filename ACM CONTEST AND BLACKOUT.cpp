#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct edge 
{
	int u, v, w;
	bool used;
	edge(){}
	edge(int a, int b, int p)
	{
		u=a;
		v=b;
		w=p;
		used=false;
	}
	bool operator < ( edge x ) const
	{
		return w<x.w;
	}
};
int parent[100];
edge a[10000];
int n, m;
void ini (int li)
{
	for(int i=0;i<li;i++)
		parent[i]=i;
}
int find(int x)
{
	if(parent[x]==x) return x;
	return parent[x]=find(parent[x]);
}
void Union(int x, int y)
{
	parent[find(x)]=find(y);
}
pair < int , int > kru ()
{
	sort(a, a+m);
	ini(n);
	int tot=0;
	int acu=0;
	for(int i=0;i<m;i++)
		if(find(a[i].u)!= find(a[i].v))
		{
			tot++;
			acu+=a[i].w;
			a[i].used=true;
			if(tot==n-1)
				return make_pair(acu, i);
			Union(a[i].u, a[i].v);
		}
	return make_pair(-1, -1);	
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		scanf("%d %d", &n ,&m);
		for(int i=0;i<m;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			a[i]=edge(u-1,v-1,w);
		}
		pair < int, int > aux=kru();//aux.first AGM1
		
	}
}
