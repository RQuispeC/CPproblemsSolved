#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
vector < vii >lista;
int  n , m, s, t;
bool vis[MAX];
vi dist;
void dikjs(int ini)
{
	dist.assign(MAX,1<<30);
	memset(vis, 0 ,sizeof vis);
	dist[ini]=0, vis[ini]=1;
	priority_queue< pii, vii, greater<pii> > q;
	q.push(pii(0, ini));
	while(!q.empty())
	{
		pii node=q.top();
		q.pop();
		int u=node.second;
		vis[u]=1;
		if(u==t) break;
		for(int i=0;i<lista[u].size();i++)
		{
			int v=lista[u][i].second;
			int cost=lista[u][i].first;
			if(!vis[v])
			{
				if(dist[v] > dist[u] + cost)
				{
					dist[v]=dist[u] + cost;
					q.push(pii(dist[v], v));
				}
			}
		}
	}
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		lista.assign(MAX, vii());
		scanf("%d %d", &n, &m);
		scanf("%d %d", &s, &t);
		while(m--)
		{
			int u,v, c;
			scanf("%d %d %d", &u, &v, &c);
			u--, v--;
			lista[u].push_back(pii(c, v));
			lista[v].push_back(pii(c, u));
		}
		s--,t--;
		dikjs(s);
		if(!vis[t])
			printf("%d\n",-1);
		else
			printf("%d\n",dist[t]);
	}
}

