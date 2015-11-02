#include<bits/stdc++.h>
#define	INF 1<<30
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
int n, m, get[15][105], memo[15][105], posCol[15];
int dp(int pos, int rem)
{
	if(pos==n) return 0;
	if(memo[pos][rem] != -1) return memo[pos][rem];
	int ans= -INF;
	for(int i=posCol[pos];i<m;i++)
	{
		if(i+1>rem) break;
		ans=max(ans, get[pos][i] + dp(pos+1, rem - i-1));
	}	
	return memo[pos][rem] = ans;
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d %d", &n , &m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%d", &get[i][j]);
				memo[i][j]=-1;
			}
		for(int i=0;i<n;i++)
		{
			memo[i][m]=-1;	
			posCol[i] = lower_bound(get[i], get[i] + m, 5) - get[i];
		}	
		int bestAver = dp(0, m);
		if(bestAver<0)	
			printf("Peter, you shouldn't have played billiard that much.\n");
		else	
			printf("Maximal possible average mark - %.2lf.\n", (1e-9 + bestAver)/n); //trick for UVA server
	}
}

