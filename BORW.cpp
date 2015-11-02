#include<bits/stdc++.h>
#define MAX 205
using namespace std;
int n , memo[MAX][MAX][MAX], a[MAX];
int dp(int pos , int lastW, int lastB)
{
	if(pos>=n) return 0;
	if(memo[pos][lastW][lastB]!=-1) return memo[pos][lastW][lastB];
	int ans=MAX;
	ans=min(ans, 1+ dp(pos+1,lastW, lastB));
	if(a[pos]>a[lastW])
		ans=min(ans, dp(pos+1, pos, lastB));
	if(a[pos]<a[lastB])
		ans=min(ans, dp(pos+1, lastW, pos));
	return memo[pos][lastW][lastB]=ans;
}
int main()
{
	while(scanf("%d", &n)==1)
	{
		if(n<=0) break;
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		a[203]=-1, a[204]=1000005;
		memset(memo, -1, sizeof memo);
		printf("%d\n", dp(0, 203, 204));
	}
}

