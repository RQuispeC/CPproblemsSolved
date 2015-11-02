#include<bits/stdc++.h>
#define MAX  100005
using  namespace std;
typedef vector < int  > vi;
int t, n, ans[MAX];
vector < vi > lista;
int dfs ( int u )
{
	if(lista[u].size()==0)  //leaf
		return ans[u]=1;
	priority_queue < int , vi , greater < int >  >	q;
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		dfs(v);
		q.push(ans[v]);
	}
	double cant = (t/100.0)*(double)lista[u].size();
	double tot = 0.0;
	ans[u]=0;
	while(tot < cant)
	{
		ans[u]+=q.top();
		q.pop();
		tot = tot + 1.0;
	}
	return ans[u];
}
int main()
{
	while(scanf("%d %d", &n , &t))
	{
		if(n==0 && t==0 ) break;
		lista.assign(MAX, vi());
		for(int i=1;i<=n;i++)
		{
			int u;
			scanf("%d", &u);
			lista[u].push_back(i);
		}
		printf("%d\n", dfs(0));
	}
}


