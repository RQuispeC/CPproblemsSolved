#include<bits/stdc++.h>
#define MAX (1<<16) + 5
using namespace std;
typedef vector < int >   vi;
int p[MAX],n;
bool vis[MAX];
struct node 
{
	int i, deg, sum;
	node(){}
	node(int a, int b, int c)
	{
		i=a, deg=b , sum = c;
	}
	bool operator < (node x) const
	{
		return  deg < x.deg;
	}
};
node a[MAX];
vector < vi > lista;
int fun(int tot, int sum)
{
	int ans=0;
	for(int mask=0;mask<31;mask++)
		if((1<<mask) & tot)
		{
			if(!((1<<mask) & sum))
			{
				ans|=(1<<mask);	
			}	
		}
		else
		{
			ans|=((1<<mask) & sum);
		}
	return abs(ans);	
}
int main()
{
	memset(p, -1,sizeof p);
	memset(vis , 0, sizeof vis);
	lista.assign(MAX, vi());
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int deg, sum;
		scanf("%d %d", &deg, &sum);
		a[i]=node(i, deg,sum);
	}
	
	queue < int > q;
	int tot=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].deg==1)
		{
			q.push(a[i].i);
		}
		if(a[i].deg==0)
				tot++;
	}
	
	while(!q.empty())
	{
		if(tot==n-1) break;
		int sum=0;
		int u=q.front();
		q.pop();
		if(a[u].deg - lista[u].size()==0 ) continue;
		vis[u]=1;
		tot++;
		for(int j=0;j<lista[u].size();j++)
			sum = sum xor lista[u][j];
		int pad=fun(a[u].sum, sum);
		lista[pad].push_back(u);
		p[u]=pad;
		if(a[pad].deg - lista[pad].size()==1)
			q.push(pad);
		vis[pad]=1;
	}
	
	tot=0;
	for(int i=0;i<n;i++)
		if(p[i]>=0)
			tot++;
	cout<<tot<<endl;
	for(int i=0;i<n;i++)
		if(p[i]>=0)
			printf("%d %d\n", i, p[i]);
}
