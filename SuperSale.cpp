#include<bits/stdc++.h>
using namespace std;
int n, memo[1005][35], w[1005], c[1005], memoP[35];
int dp(int pos , int rem)
{
	if(pos==n)  return 0;
	if(rem == 0) return 0;
	if(memo[pos][rem]!=-1) return memo[pos][rem];
	int ans;
	if(c[pos] > rem)
		ans=dp(pos+1, rem);
	else
		ans=max(dp(pos+1, rem), w[pos] + dp(pos+1, rem - c[pos]));
	return memo[pos][rem]=ans;	
}
int dpP( int rem)
{
	if(memoP[rem] != -1)
		return memoP[rem];
	memset(memo, -1, sizeof memo);
	int ans=dp(0, rem);
	return memoP[rem]=ans;
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for(int  i=0;i<n;i++)
			scanf("%d %d", &w[i], &c[i]);
		memset(memoP, -1, sizeof memoP);
		int g;
		scanf("%d", &g);
		int ans=0;
		for(int i=0;i<g;i++)
		{
			int maxW;
			scanf("%d", &maxW);
			ans+=dpP(maxW);
		}
		printf("%d\n", ans);
	}
}
