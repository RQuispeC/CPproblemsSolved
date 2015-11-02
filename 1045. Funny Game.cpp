#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n , k;
vector <  vector < int > > lista;
bool vis[MAX];
bool dfs(int u)
{
	vis[u]=1;
	bool ans=0;
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		if(!vis[v])
		{
			ans=ans or !dfs(v);
		}
	}
	return ans;
}
int main()
{
	memset(vis, 0, sizeof vis);
	lista.assign(MAX, vi());
	scanf("%d %d", &n , &k);
	for(int i=1;i<n;i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		lista[u].push_back(v);
		lista[v].push_back(u);
	}
	k--;
	sort(lista[k].begin(), lista[k].end());
	int ans=-1;
	vis[k]=1;
	for(int i=0;i<lista[k].size();i++)
		if(!dfs(lista[k][i]))
		{
			ans=lista[k][i];
			break;
		}
	if(ans>=0)
		printf("First player wins flying to airport %d\n", ans+1);
	else
		printf("First player loses\n");
}


