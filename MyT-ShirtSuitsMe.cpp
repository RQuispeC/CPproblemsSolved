#include<bits/stdc++.h>
#define MAX 40
#define INF 1000000000
using namespace std;
int res[MAX][MAX];
vector < int  > a[MAX]; 
// 0-s
// 1...30 - pers
// 31..36 - tshirs
// 37-t
int n, m, s=0, t=37, mf,f;
vector < int > p;
bool visited [MAX];
void ini()
{
	for(int i=1;i<=m;i++)
	{
		a[s].push_back(i);
		a[i].push_back(s);
		res[s][i]=1;
		res[i][s]=0;
	}
	int uni=n/6;
	for(int i=31;i<=36;i++)
	{
		a[i].push_back(t);
		a[t].push_back(i);
		res[i][t]=uni;
		res[t][i]=0;
	}
}
void argument( int v, int minEdge)
{
	if(v==s)
	{
		f=minEdge;
		return;
	}
	else if(p[v]!=-1)
	{
		argument(p[v], min (minEdge, res[p[v]][v]) );
		res[p[v]][v]-=f;
		res[v][p[v]]+=f;
	}	
}
void edmons_karp()
{
	mf=0;
	while(1)
	{
		f=0;
		memset(visited, false, sizeof visited);
		p.assign(MAX, -1);
		queue < int  > q;
		q.push(s);
		visited[s]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			if(u==t) break;
			for(int i=0;i<a[u].size();i++)
			{
				int v=a[u][i];
				if(!visited[v] && res[u][v]>0)
				{
					q.push(v);
					visited[v]=1;
					p[v]=u;
				}
			}
		}
		argument(t, INF);
		if(f==0) break;
		mf+=f;
		
	}
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		memset(res, 0 , sizeof res);
		scanf("%d %d",&n, &m );
		for(int i=0;i<MAX;i++)
			a[i].clear();
		ini();
		for(int i=1;i<=m;i++)
		{
			string s1,s2;
			cin>>s1>>s2;
			int p1,p2;
			if(s1=="XS") p1=31;
			else if(s1=="S") p1=32;
			else if(s1=="M") p1=33;
			else if(s1=="L") p1=34;
			else if(s1=="XL") p1=35;
			else p1=36;
			if(s2=="XS") p2=31;
			else if(s2=="S") p2=32;
			else if(s2=="M") p2=33;
			else if(s2=="L") p2=34;
			else if(s2=="XL") p2=35;
			else p2=36;
			a[i].push_back(p1);
			a[i].push_back(p2);
			a[p1].push_back(i);
			a[p2].push_back(i);
			res[i][p1]=1;
			res[i][p2]=1;
			res[p1][i]=0;
			res[p2][i]=0;
		}
		edmons_karp();
		//cout<<mf<<endl;
		if(mf==m)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
}

