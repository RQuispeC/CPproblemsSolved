#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,  s;
struct edge 
{
	int u, v, w;
	edge(){}
	edge(int a, int b, int p)
	{
		u=a;
		v=b;
		w=p;
	}
	bool operator < (edge x) const
	{
		return w<x.w;
	}
};
edge a[125000];
int parents[505];
int elementos[505];
void ini ( int li)
{
	for(int i=0;i<li;i++)
	{
		parents[i]=i;
		elementos[i]=1;
	}
}	
int find (int x)
{
	if(parents[x]==x) 
		return x;
	else 
		return parents[x]=find(parents[x]);
}
void Union(int x, int y)
{
	int rx=find (x);
	int ry=find (y);
	if (rx!= ry)
	{
		elementos[rx]++;
		elementos[ry]++;
	}
	parents[ry]=rx;	
}
int kru (int m)
{
	sort (a, a+m);
	ini (n);
	int dis=n;
	int ans=0;
	int tot=0;
	for(int i=0;i<m;i++)
	{
		int fu=find (a[i].u);
		int fv=find (a[i].v);
		if(fu!=fv)
		{
			dis--;
			tot++;
			if(dis==s || tot+1==n)
				return max (ans, a[i].w);
			ans=max(ans, a[i].w);
			Union(a[i].u, a[i].v);	
		}
	}
	return ans;
}
int main()
{
	int x[505];
	int y[505];
	int tested;
	cin>>tested;
	while(tested--)
	{
		scanf("%d %d", &s, &n);
		for(int i=0;i<n;i++)
			scanf("%d %d", &x[i], &y[i]);
		int k=0;	
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				a[k++]=edge(i,j, (x[i]-x[j])*(x[i]-x[j])  + (y[i]-y[j])*(y[i]-y[j])  );		
		int ans=kru(k);
		printf("%.2f\n", (double)sqrt((double)ans));	
	}
}
