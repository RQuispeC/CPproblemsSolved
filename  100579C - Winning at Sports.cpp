#include<bits/stdc++.h>
#define MAX 2005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
const ll MOD = 1000000007;
int memo1[MAX][MAX], memo2[MAX][MAX], a, b;
int dp1(int x, int y)
{
	if(x==a && y==b) return 1;
	if(memo1[x][y]!=-1) return memo1[x][y];
	ll ans=0ll;
	if(x+1<=a)
		ans=ll(dp1(x+1,y)) % MOD;
	if(y+1 < x && y+1<=b)
		ans+=ll(dp1(x, y+1)) % MOD;
	return memo1[x][y]=(int)(ans % MOD);
}
int dp2(int x, int y)
{
	if(x==a && y==b) return 1;
	if(memo2[x][y]!=-1) return memo2[x][y];
	ll ans=0ll;
	if(y==b)
		ans=ll(dp2(x+1,y)) % MOD;
	else
	{
		if(y+1<=b)
			ans=ll(dp2(x,y+1)) % MOD;
		if(x+1 <= y && x+1<=a)
			ans+=ll(dp2(x+1, y)) % MOD;
	}	
	return memo2[x][y]=(int)(ans % MOD);
}
pii sol()
{
	if(b==0) return pii(1,1);
	int f=dp1(1,0);
	int s=dp2(0,1);
	return pii(f,s);
}
int main()
{
	int test;
	scanf("%d", &test);
	for(int te=1;te<=test;te++)
	{
		memset(memo1, -1, sizeof memo1);
		memset(memo2, -1, sizeof memo2);
		scanf("%d-%d",&a, &b);
		pii ans=sol();
		printf("Case #%d: %d %d\n", te, ans.first , ans.second);
	}
}

