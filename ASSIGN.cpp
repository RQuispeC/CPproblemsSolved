#include<bits/stdc++.h>
#define MAX 25
using namespace std;
typedef vector < long long  > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
const int INF = (1<<30);
const int MOD = 1000000007;
int a[MAX][MAX], n;
ll memo[21][1<<21];
inline ll dp(int pos, int used)
{
	if(pos==n) return used == (1<<n) -1;
	if(memo[pos][used]!=-1) return memo[pos][used];
	ll ans=0ll;
	for(int i=0;i<n;i++)
		if(a[pos][i] && !(1<<i & used))
			ans+=dp(pos+1, used | 1<<i);
	return memo[pos][used]=ans;
}
ll sol()
{
	for(int i=0;i<n;i++)
		memo[i][(1<<n)-1]=1;
	for(int j=(1<<n)-2;j>=0; j--)	
		for(int i=0;i<n;i++)
			dp(i,j);
	return dp(0,0);
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		int n0, n1, f;
		n0=n1=f=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				scanf("%d", &a[i][j]);
				if(a[i][j]) n1++;
				else n0++;
			}
		for(int i=0;i<=n;i++)
			for(int j=0;j<(1<<n);j++) 
				memo[i][j]=-1;
		cout<<sol()<<endl;
		//cout<<dp(0,0)<<endl;
	}
}

