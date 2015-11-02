#include<bits/stdc++.h>
#define MAX 30005
using namespace std;
int n , island[MAX], d, memo[500][MAX], maxN, offset;
int dp(int leght, int pos)
{
	if(pos>maxN) return 0;
	if(memo[leght + offset][pos] != -1 ) return memo[leght + offset][pos];
	int ans=island[pos];
	if(leght - 1 > 0)
		ans=max(ans, island[pos] + dp(leght-1, pos + leght-1));
	ans=max(ans, island[pos] + dp(leght, pos + leght));
	ans=max(ans, island[pos] + dp(leght+1, pos + leght+1));
	return memo[leght + offset][pos] = ans;
}
int main()
{
	maxN=0;
	memset(island, 0, sizeof island);
	memset(memo, -1, sizeof memo);
	scanf("%d %d", &n, &d);
	offset=250 - d;
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d", &p);
		island[p]++;
		maxN=max(maxN, p);
	}
	printf("%d\n", dp(d, d));
}

