#include<bits/stdc++.h>
#define MAX 105
#define INF 100000000
using namespace std;
vector < int >  p ;
int res[MAX][MAX];
vector < int  > a[MAX];
int mf,f, s, t, n, m;
bool visited [MAX];
void argumentPath(int v, int minEdge)
{
	if(v==s)
	{
		f=minEdge;
		return ;
	}
	else
	{
		if(p[v] !=-1)
		{
			argumentPath(p[v], min( minEdge, res[ p[v] ][v] ));
			res[p[v]][ v ] -=f;
			res[v][ p[v] ] +=f;
		}
	}
}
void edmons_karp()
{
		mf=0;
		while(1)
		{
			f=0;
			memset(visited, false, sizeof visited);
			queue < int  > cola;
			cola.push(s);
			p.assign(MAX, -1);
			visited[s]=1;
			while(!cola.empty())
			{
				int u=cola.front();
				cola.pop();
				if(u==t) break;
				for(int i=0;i<a[u].size();i++)
				{
					int v=a[u][i];
					if(res[u][v] > 0   && !visited[v])//exist an edge and !visited
					{
						cola.push(v);
						p[v]=u;
						visited[v]=true;
					}
				} 
			}
			argumentPath(t, INF);			
			if( f==0 ) break;
			mf+=f;
		}
}
int main()
{
	int cas=1;
	while(cin>>n)
	{
		if(n<=0 ) break;
		memset(res, 0, sizeof res);
		scanf("%d %d %d", &s, &t, &m);
		s--;t--;
		for(int i=0;i<m;i++)
		{
			int u, v, cap;
			scanf("%d %d %d", &u,  &v, &cap);
			u--;v--;
			a[u].push_back(v);
			a[v].push_back(u);
			res[u][v]+=cap;
			res[v][u]+=cap;
		}
		edmons_karp();
		cout<<"Network "<<cas++<<endl;
		cout<<"The bandwidth is "<<mf<<"."<<endl<<endl;
	}
	
}

