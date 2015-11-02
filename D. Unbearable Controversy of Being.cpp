#include<bits/stdc++.h>
#define MAX 3005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
bool a[MAX][MAX];
vector < vi > lista;
int n,m;
ll comb(int x)
{
	return ll(x*ll(x-1))/2ll;
}
int main()
{
	memset(a, 0, sizeof a);
	lista.assign(MAX,vi());
	scanf("%d %d", &n, &m);
	for(int i=0;i<m;i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		lista[u].push_back(v);
		a[u][v]=1;
	}
	ll ans=0ll;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				int numCon=0;
				for(int k=0;k<lista[i].size();k++)
					if(lista[i][k] != i && lista[i][k] != j && a[lista[i][k]][j])
						numCon++;
				ans+=comb(numCon);
			}
		}
	cout<<ans<<endl;	
}

