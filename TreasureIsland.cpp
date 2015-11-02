#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#define MAX   65
using namespace std;
int n, m; 
vector < int > a[MAX];
bool rea[MAX][MAX];
bool posible [MAX] ;
struct tes
{
	int ind, edges;
	tes(){}
	tes(int i , int e)
	{
		ind=i;
		edges=e;
	}
	bool operator < (tes x) const
	{
		return edges < x.edges;
	}
};
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		scanf("%d %d", &n  ,&m);
		for(int i=0;i<n;i++)
		{
			a[i].clear();
		}
		memset(rea, 0, sizeof rea);
		for(int i=0;i<m;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			if(!rea[u][v])
			{
				a[u].push_back(v);
				a[v].push_back(u);
				rea[u][v]=1;
				rea[v][u]=1;
			}
		}
		vector < tes   >  teso;
		teso.clear();
		for(int i=0;i<n;i++)
		{
			teso.push_back(tes(i, a[i].size()));	
		}
		sort(teso.begin(), teso.end());
		memset(posible, 1, sizeof posible);
		int ans=0;
		for(int i=0;i<teso.size();i++)
		{
			int node=teso[i].ind;
			//cout<<node<<endl;
			if(posible[node])
			{
				//cout<<node<<"  ** "<<endl;
				ans++;
				posible[node]=0;
				for(int i=0;i<a[node].size();i++)
				{
					posible[a[node][i]]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
}
