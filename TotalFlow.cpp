#include<bits/stdc++.h>
#define MAX 70
#define INF 1e9
using namespace std;
typedef vector < int > vi;
int s,t,mf, f, adjM[MAX][MAX], p[MAX];
vector < vi > lista;
bool visited[MAX];
void argument(int v, int best)
{
	if(v==s)
	{
		f=best;
		return;
	}
	else if(p[v]!=-1)
	{
		argument(p[v], min (best, adjM[p[v]][v]));
		adjM[p[v]][v]-=f;
		adjM[v][p[v]]+=f;
	}		
}
int edmons_karp()
{
	mf=0;
	while(true)
	{
		memset(visited, 0, sizeof visited);
		memset(p, -1, sizeof p);
		f=0;
		queue < int  > q;
		q.push(s);
		visited[s]=true;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(u==t) break;
			for(int i=0;i<lista[u].size();i++)
			{
				int v=lista[u][i];
				if(!visited[v])
				{
					visited[v]=true;
					q.push(v);
					p[v]=u;
				}
			}			
		}
		argument(t, INF);
		if(f==0) break;
		mf+=f;
	}
	return mf;
}
int main()
{
	vi xxx;
	xxx.clear();
	lista.assign(MAX, xxx);
	memset(adjM, 0, sizeof adjM);
	int tot;
	scanf("%d", &tot);
	for(int i=0;i<tot;i++)
	{
		char a,b;
		int w;
		cin>>a>>b>>w;
		lista[a-'A'].push_back(b-'A');
		lista[b-'A'].push_back(a-'A');
		adjM[a-'A'][b-'A']=w;
		adjM[b-'A'][a-'A']=w;
	}
	s='A'-'A';
	t='Z'-'A';
	cout<<edmons_karp()<<endl;
}

