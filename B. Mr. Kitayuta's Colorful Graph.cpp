#include<bits/stdc++.h>
#define MAX  105
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n, m, q;
vector < vi > lista[MAX];
bool vis[MAX][MAX];
int ans[MAX][MAX];
vi comp;
void dfs(int c, int u)
{
	comp.push_back(u);
	vis[c][u]=1;
	for(int i=0;i<(int)lista[c][u].size();i++)
	{
		int v=lista[c][u][i];
		if(!vis[c][v])
			dfs(c, v);
	}
}
void getAll()
{
	memset(ans, 0, sizeof ans);
	for(int c=0;c<m;c++)
	{
		for(int u=0;u<n;u++)
		{
			if(!vis[c][u])
			{
				comp.clear();
				dfs(c, u);
				for(int i=0;i<comp.size();i++)
					for(int j=i+1;j<comp.size();j++)
					{
						ans[comp[i]][comp[j]]++;
						ans[comp[j]][comp[i]]++;
					}	
			}	
		}	
	}
}
int main()
{	
	for(int i=0;i<MAX;i++)
		lista[i].assign(MAX, vi());
	memset(vis, 0, sizeof vis);
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		c--, u--, v--;
		lista[c][u].push_back(v);
		lista[c][v].push_back(u);
	}
	getAll();
	scanf("%d", &q);
	while(q--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		printf("%d\n", ans[u][v]);
	}
	
}

