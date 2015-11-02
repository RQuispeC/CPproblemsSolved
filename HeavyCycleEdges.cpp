#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int parent[1005];
void ini(int li)
{
	for(int i=0;i<li;i++)
		parent[i]=i;
}
int find(int x)
{
	if(parent[x]==x) return x;
	return parent[x]=find(parent[x]);
}
int Union(int x, int y)
{
	return parent[find(x)]=find(y);
}
struct edge
{
	int u,v;
	long long w	;
	bool used;
	edge(){}
	edge(int a, int b, long long p)
	{
		u=a;v=b;
		w=p;
		used=false;
	}
	bool operator < (edge x) const
	{	
		return w<x.w;
	}
};
edge a[25005];
int n, m ;
void kru()
{
	sort(a, a+m);
	ini(n);
	int to=0;
	for(int i=0;i<m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			//cout<<a[i].u<<"   "<<a[i].v<<" : "<<a[i].w<<endl; 
			a[i].used=true;
			to++;
			if(to==n-1 ) return ;
			Union(a[i].u, a[i].v);
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		if(n<=0 && m<=0 )  break;
 		for(int i=0;i<m;i++)
		{
			int u, v;
			long long w;
			scanf("%d %d", &u, &v);
			cin>>w;
			a[i]=edge(u,v,w);
		}
		kru();
		bool flag=false;
		int to=0;
		for(int i=0;i<m;i++)
		{
			if(!a[i].used)
			{
				to++;
			}
		}
		//cout<<"toto :  "<<to<<endl;
		if(to==0)
			cout<<"forest"<<endl;
		else
		{
			for(int i=0;i<m;i++)
			{
				if(!a[i].used)
				{
					cout<<a[i].w;
					to--;
					if(to>=1) cout<<" ";
				}
			}
			cout<<endl;
		}	
	}
}
