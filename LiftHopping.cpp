#include<bits/stdc++.h>
#define MAX 510
#define INF 1e9
using namespace std;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef vector < int  > vi;
vector < vii > lista;
vi dist;
bool piso[5][105], visited[MAX];
int t[5], n, k;
struct node
{
	int u, w;
	node(){}
	node(int U, int W)
	{
		u=U, w=W;
	}
	bool operator  < (node x) const
	{
		return w > x.w;
	}
};
void dijk( int  ini )
{
	memset(visited, 0 ,sizeof visited);
	dist.assign(MAX, INF);
	dist[ini]=0;
	priority_queue < node > q;
	q.push(node(ini, 0));
	while(!q.empty())
	{
		node top=q.top();
		q.pop();
		int u=top.u;
		int w=top.w;
		visited[u]=1;
		for(int i=0;i<lista[u].size();i++)
		{
			pii v = lista[u][i];
			if(dist[u] + v.second < dist[v.first])
			{
				q.push(node(v.first , dist[u] + v.second));
				dist[v.first] = dist[u] + v.second;
			}
		}
	}
}
void llenar1(int ind, vi a)
{
	int ini=ind*100;
	for(int i=0;i<a.size();i++)
	{
		for(int j=i+1;j<a.size();j++)
		{
			lista[a[i]+ini].push_back(pii(a[j]+ini, abs(a[i]-a[j])*t[ind]));
			lista[a[j]+ini].push_back(pii(a[i]+ini, abs(a[i]-a[j])*t[ind]));
		}
	}
}
void llenar2()
{
	int li=101;
	vi a;
	for(int j=0;j<li;j++)
	{
		if(a.size() > 0) a.clear();
		for(int i=0;i<n;i++)
		{
			if( piso[i][j] )
				a.push_back( j + i*100 );
		}
		for(int i=0;i<a.size();i++)
			for(int k=i+1;k<a.size();k++)
			{
				lista[a[i]].push_back(pii(a[k], 60));
				lista[a[k]].push_back(pii(a[i], 60));
			}	
		
	}
}
int main()
{
	string s;
	while(getline(cin,s))
	{
		memset(piso, 0, sizeof piso);
		vector < int > a;
		a.clear();
		stringstream in1(s);
		int aux;
		while(in1>>aux)
		{		
			a.push_back(aux);
		}
		n=a[0], k=a[1];
		int  j=0;
		getline(cin,s);
		stringstream in2(s);
		while(in2>>aux)
		{		
			t[j++]=aux;
		}
		lista.assign(MAX, vii());
		for(int i=0;i<n;i++)
		{
			getline(cin,s);
			stringstream in3(s);
			a.clear();
			while(in3>>aux)
			{
				piso[i][aux]=1;
				a.push_back(aux);
			}
			llenar1(i, a);
		}
		llenar2();
		int ans=INF;
		for(int i=0;i<n;i++)
		{
			int ini=i*100;
			dijk(ini);
			for(int j=0;j<n;j++)
			{
				int end=k+j*100;
				ans=min(ans, dist[end]);
			}
		}
		if(ans==INF)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<ans<<endl;
	}
}

