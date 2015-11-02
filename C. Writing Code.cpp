#include<bits/stdc++.h>
#define	INF 1<<30
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 505
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
typedef pair< int64, int64 > pll;
int MOD, n, m, b, a[MAX], dp[2][MAX][MAX];
int sol()
{
	dp[0][0][0] = 1;
	for(int pos=1;pos<=n;pos++)
	{
		int i=pos & 1;
		for(int j=0;j<=m;j++)
			for(int k=0;k<=b;k++)
			{
				dp[i][j][k] = dp[i ^ 1][j][k];
				if(j>=1 && k>=a[pos-1])
					dp[i][j][k]+=dp[i][j-1][k-a[pos-1]];
				dp[i][j][k]%=MOD;	
			}
	}
	int ans=0;
	for(int i=0;i<=b;i++)
	{
		ans+=dp[n & 1][m][i];
		ans%=MOD;
	}
	return ans;
}
int main()
{
	scanf("%d %d %d %d", &n, &m, &b, &MOD);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	memset(dp, 0, sizeof dp);
	printf("%d\n", sol());
}

