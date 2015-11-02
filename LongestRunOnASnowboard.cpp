#include<bits/stdc++.h>
#define MAX 110
#define INF 1e9
using namespace std;
typedef vector < int > vi;
vector < vi > lista;
vi toposort;
int a[MAX][MAX], b[MAX][MAX];
int row, column;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool visited[MAX*MAX];
void dfs(int u)
{
	visited[u]=1;
	for(int i=0;i<lista[u].size();i++)
	{
		int v=lista[u][i];
		if(!visited[v])
			dfs(v);
	}
	toposort.push_back(u);
}
bool validate(int i, int j)
{
	return i>=0 && j>=0 && i<row && j<column;
}
void generate(int n)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			for(int t=0;t<4;t++)
			{
				int ni=i+dy[t], nj=j+dx[t];
				if(validate(ni, nj))
					if(a[ni][nj] < a[i][j])
						lista[b[i][j]].push_back(b[ni][nj]);
			}
		}	
	}
	memset(visited, 0, sizeof visited);
	for(int i=0;i<n;i++)
		if(!visited[i])
			dfs(i);
	reverse(toposort.begin(), toposort.end());
}
int main()
{
	vi dist;
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		lista.assign(MAX*MAX, vi());
		dist.assign(MAX*MAX, -1);
		toposort.clear();
		string name;
		cin>>name>>row>>column;
		int n=0;
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				scanf("%d", &a[i][j]), b[i][j]=n++;
		generate(n);
		int ans=-1;
		for(int i=0;i<toposort.size();i++)//MAX path
		{
			int u=toposort[i];
			ans=min(ans , dist[u]);
			for(int j=0;j<lista[u].size();j++)
			{
				int v=lista[u][j];
				dist[v]=min(dist[v], dist[u] - 1); // update distance
			}
		}
		cout<<name<<": "<<-ans<<endl;
	}
}

