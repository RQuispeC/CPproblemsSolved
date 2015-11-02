#include <bits/stdc++.h>
#define MAX ((int)1e5 * 2) + 10
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n, a[MAX];
int memo[(int)(1e5) +5];
int dp(int num, int pos)
{
	if((pos - 1) ==n) 
		return 1;
	if((pos-1)>n )
		return 0;
	if(memo[pos] != -1 )return memo[pos];
	int nextPos=pos + num +1;
	if((nextPos-1) <=n)
		return memo[pos]=dp(a[nextPos], nextPos);
	else
		return memo[pos]=0;
}
int main()
{
	while(cin>>n)
	{
		memset(memo, -1, sizeof memo);
		for(int i=1;i<=n;i++)
			scanf("%d", &a[i]);	
		for(int i=1;i<=n;i++)
		{
			memo[0]=-1;
			if(dp(i, 0))
				printf("%d\n", i);
		}		
	}
}

