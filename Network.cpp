#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
int p[MAX], n, m ,k;
void ini(int l)
{
	for(int i=0;i<l;i++)
		p[i]=i;
}
int find(int x)
{
	if(p[x]==x)
		return x;
	return p[x]=find(p[x]);
}
void Union(int x, int y)
{
	p[find(x)]=find(y);
}
int main()
{
	while(cin>>n>>m>>k)
	{
		ini(n);
		for(int i=0;i<m;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			Union(u, v);
		}
		for(int i=0;i<k;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			if(find(u) == find(v))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;	
		}
	}
}

