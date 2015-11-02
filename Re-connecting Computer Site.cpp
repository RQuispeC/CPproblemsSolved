#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define MAX 1000055
using namespace std;
struct edge
{
	int u , v, weight;
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
int n, m  ,k;
edge lista[MAX];
edge nuevos[15];
edge t[MAX];
int p[MAX];
void ini (int l)
{
	for(int i=0;i<l;i++)
		p[i]=i;
}
int find(int x)
{
	if(x==p[x]) return x;
	return p[x]=find(p[x]);
}	
void Union(int x, int y)
{
	p[find(x)]=find(y);
}
int krushkal(int l, edge listInc[]) // l tamaño de lista, lAux numero MAX de nodos
{
	sort(listInc, listInc +l);
	ini(n);
	long long ans=0ll;
	int con=0;
	for(int i=0;i<l;i++)
	{
		if(find(listInc[i].u)!=find(listInc[i].v))
		{
			Union(listInc[i].u , listInc[i].v  );
			con++;
			ans+=listInc[i].weight;
			if(con==n-1)
				return ans;
		}
	}
	return -1;
}
int main()
{
	bool blank=false;
	while(cin>>n)
	{
		if(blank ) cout<<endl;
		blank=true;
		long long temp=0;
		for(int i=1;i<n;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u , &v, &w);
			u--; v--;
			t[i-1]=edge(u, v, w);	
			temp+=w;
		}
		scanf("%d", &k);
		for(int i=0;i<k;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u , &v, &w);
			u--; v--;
			nuevos[i]=edge(u, v, w);	
		}
		scanf("%d", &m);
		for(int i=0;i<m;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u , &v, &w);
			u--; v--;
			lista[i]=edge(u, v, w);	
		}
		cout<<temp<<endl;
		int aux=0;
		for(int i=m;i<m+k;i++)
			lista[i]=nuevos[aux++];
		//for(int i=0;i<m+k;i++)
			//cout<<lista[i].u<<"  "<<lista[i].v<<"  : " <<lista[i].weight<<endl;
		cout<<krushkal(m+k, lista )<<endl;
	}
}
