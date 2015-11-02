#include<bits/stdc++.h>
#define MAX (int)1e5 + 5
using namespace std;
typedef long long ll;
int p[2*MAX], n , m, numComp[2*MAX], id[2*MAX], node;
ll sum[2*MAX];
void ini(int l)
{
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		numComp[i]=1;
		sum[i]=ll(i);
		id[i]=i;
	}
}
int find(int x)
{
	if(p[x]==x)
		return x;
	return p[x]=find(p[x]);
}
void query1(int x, int y)
{
	int X=find(id[x]);
	int Y=find(id[y]);
	if(X != Y)
	{
		p[X]=Y;
		sum[Y]+=sum[X];
		numComp[Y]+=numComp[X];
	}
}
void query2(int x, int y)
{
	int X=find(id[x]);
	int Y=find(id[y]);
	if(X != Y)
	{
		//crear nuevo nodo
		sum[node]=x;
		numComp[node]=1;
		
		p[node]=Y;
		sum[Y]+=x;
		numComp[Y]++;
		sum[X]-=x;
		numComp[X]--;
		id[x]=node++;
	}
}	
void query3(int x)
{
	int X=find(id[x]);
	cout<<numComp[X]<<" "<<sum[X]<<endl;
}	
int main()
{
	while(cin>>n>>m)
	{
		ini(n);
		node=n+1;
		for(int i=0;i<m;i++)
		{
			int op;
			scanf("%d", &op);
			if(op==1)
			{
				int x, y;
				scanf("%d %d", &x, &y);
				query1(x, y);
			}	
			else if(op==2)
			{
				int x, y;
				scanf("%d %d", &x, &y);
				query2(x, y);
			}
			else
			{
				int x;
				scanf("%d", &x);
				query3(x);
			}
		}
	}
}
