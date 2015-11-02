#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define MAX 1005
using namespace std;
int c, p;
int memo[MAX][MAX];
vector <  vector < int > > lista [MAX]; 
// DAG (directet aciclic graph)
int dp(int x, int y)
{
	if(x==y) return 0; //chocan en algun nodo
	if(x==1) return 1; //llega a la ciudad principal
	if(memo[x][y]!=-1) return memo[x][y];
	int ans=0;//asumimos que no existe disjoint water supply
	for(int i=0;i<lista[y].size();i++)
		if(dp( min(x, lista[y][i])  , max(x, lista[y][i]) ) )
		{
			ans=1;
			break;
		}
	return memo[x][y]=ans;	
}
int main()
{
	while(cin>>c>>p)
	{
		for(int i=1;i<=c;i++)
			if(lista[i].size()>0) lista[i].clear();
		for(int i=0;i<p;i++)//guardamos en sentido contrario
		{
			int u,v;
			scanf("%d %d", &u, &v);
			lista[max(u, v)].push_back(min(u, v));
		}
		memset(memo, -1, sizeof memo);
		int ans=c-1;
		for(int i=0;i<=c;i++)
			for(int j=i+1;j<=c;j++)
				ans+=dp(i, j);
		cout<<ans<<endl;				
	}
}
