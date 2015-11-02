#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef vector < int > vi;
vector <  vi > lista;
int n, m, memo[MAX][MAX];
int dp(int u, int v) // u=MIN(mas alto), v=MAX(mas bajo)
{
	if(u == 0) return 1;
	if(u == v) return 0;
	if(memo[u][v] != -1) return memo[u][v];
	int ans=0;
	//cout<<u<<" - "<<v<<endl;
	for(int i=0;i<lista[v].size();i++)
	{
		int adj=lista[v][i];
		ans = ans + dp( min(u,adj) , max(u,adj) );
		if(ans)
			break;
	}
	return memo[u][v] = ans; 
}
int main()
{
	while(cin>>n>>m)
	{
		memset(memo, -1, sizeof memo);
		lista.assign(MAX, vi());
		for(int i=0;i<m;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			u--,v--;
			lista[v].push_back(u);
		}
		int ans=n-1;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<n;j++)
				ans+=dp(i,j);
		printf("%d\n", ans);
	}
}



