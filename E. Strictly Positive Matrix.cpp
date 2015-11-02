#include<bits/stdc++.h>
#define MAX  2005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n, m,dfsCont,dfs_num[MAX], dfs_low[MAX], numComp;
vector < vi > lista;
string ans[MAX];
vi pila, comp;
bool vis[MAX];
void tarjan(int u)
{
	dfs_low[u]=dfs_num[u]=dfsCont++;
	vis[u]=1;
	pila.push_back(u);
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		if(dfs_num[v]==-1)
			tarjan(v);
		if(vis[v])	
			dfs_low[u]=min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u]==dfs_num[u])
	{
		while(true)
		{
			int v=pila.back();
			comp.push_back(v);
			pila.pop_back();
			vis[v]=0;
			if(u==v) break;
		}
		numComp++;
	}
}
int main()
{
	scanf("%d", &n);
	lista.assign(n, vi());
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int x;
			scanf("%d", &x);
			if(x)
				lista[i].push_back(j);
		}		
	pila.clear();
	memset(dfs_low, 0, sizeof dfs_low);
	memset(dfs_num, -1, sizeof dfs_num);
	memset(vis, 0, sizeof vis);
	dfsCont=0;
	numComp=0;
	tarjan(0);
	if(numComp==1 && comp.size()==n)
		printf("YES\n");
	else
		printf("NO\n");	
}

