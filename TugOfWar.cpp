#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX 101
//http://acm.uva.es/board/viewtopic.php?f=9&t=3505&p=368989&hilit=10032&sid=05559044307ca0521479e88568095313#p369598
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
int n , w[MAX], memo[MAX][51][50*450], ac[MAX];
int dp(int pos, int remN, int rem)
{
	if(pos==n || remN==0) return 0;
	if(memo[pos][remN][rem]!=-1) return memo[pos][remN][rem];
	if(rem==0 && remN!=0) return -INF;
	int posRem = n - pos, ans=0;
	if(posRem < remN) return -INF;
	if(posRem == remN) return ac[pos];
	if(posRem > remN)
	{
		ans = dp(pos+1, remN, rem);
		if(remN>=1 && w[pos]<=rem)
			ans= max(ans, w[pos] + dp(pos+1, remN -1, rem -w[pos]));
	}
	return memo[pos][remN][rem] = ans;
}
int sol(int sum)
{
	for(int i=0;i<=sum/2;i++)
		memo[n][0][i]=0;
	for(int iPos=n;iPos>=0;iPos--)
		for(int remN = 0;remN<=n/2;remN++)	
			for(int rem=0;rem<=sum/2;rem++)
				dp(iPos, remN, rem);
	return dp(0, n/2, sum/2);
}
int main()
{
	int test;
	scanf("%d", &test);
	bool blank=0;
	while(test--)
	{
		if(blank) puts("");
		blank = 1;
		scanf("%d", &n);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d", &w[i]);
			sum+=w[i];
		}
		
		for(int i=n-1;i>=0;i--)
			if(i==n - 1) ac[i] = w[i];
			else ac[i] = ac[i+1] + w[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=sum/2;k++)
					memo[i][j][k] = -1;
		//int team1 = sol(sum);
		int team1 = dp(0, n/2, sum/2);
		int team2 = sum - team1;
		
		printf("%d %d\n", min(team1, team2), max(team1, team2));
	}
}

