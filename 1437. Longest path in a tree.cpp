#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define MAX 10010
using namespace std;
int parents[MAX];
int hight [MAX];
int find( int x)
{
	if(parents[x]==x)
		return x;
	return  find(parents[x]);	
}
int HIGHT( int x)
{
	if(parents [x] == x) return 0;
	if(hight[parents[x]] != -1 ) return hight[parents [x]];
	return  hight[parents [x]] = 1+ HIGHT( parents [ x] ) ;
}
int main()
{
	int n;
	scanf("%d", &n);
	for( int i=1;i <= n;i++)
	{
		parents[i]=i;
		hight[i]=-1;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d %d", &u, &v);
		parents[v]=u;
	}
	//for(int i=1;i<=n;i++)
		//cout<<parents[i]<<"  ";
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans, HIGHT(i));
	cout<<ans<<endl;	
}
