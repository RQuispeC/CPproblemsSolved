#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int parent[105];
void ini(int li)
{
	for(int i=0;i<li;i++)
		parent[i]=i;
}
int find(int x)
{
	if(parent[x]==x)
		return x;
	return parent[x]=find(parent[x]);	
}
void Union( int x, int y)
{
	parent[find(x)]=find(y);
}
struct edge
{
	int u, v, w;
	edge(){}
	edge(int a, int b, int p)
	{
		u=a;v=b;w=p;
	}
	bool operator < (edge x) const
	{
		return x.w<w;
	}
};
int n , m;
edge a[10005];
int kru()
{
	ini(n);
	sort(a, a+m);
	int tot=0;
	int ans=1000000000;
	for(int i=0;i<m;i++)
	{
		if(find(a[i].u) != find (a[i].v))
		{
			tot++;
			ans=min(ans, a[i].w);
			if(tot==n-1)
				return ans;
			Union(a[i].u, a[i].v);	
		}
	}
	return -1;
}

int main()
{
	int tested;
	scanf("%d", &tested);
	for(int t=1;t<=tested;t++)
	{
		scanf("%d %d", &n ,&m);
		for(int i=0;i<m;i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			a[i]=edge(u,v,w);
		}
		int ans=kru();
		printf("Case #%d: %d\n", t, ans);
	}
}
