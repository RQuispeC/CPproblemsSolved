#include<vector>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int mon[4]={1,5,10,25};
int memo[4][510];
int f(int x)
{
	int ans=0;
	for(int i=0;i<4;i++)
		ans+=memo[i][x];
	return ans;	
}
void dp()
{
	memo[0][0]=memo[1][0]= memo[2][0]=memo[3][0]=0;
	for(int i=1;i<510;i++)
	{
		memo[0][i]=i;
		memo[1][i]=memo[2][i]=memo[3][i]=0;
		for(int j=0;j<4;j++)
		{	
			if(i-mon[j]>=0)
				if(f(i - mon[j]) +1 < f(i))
					for(int k=0;k<4;k++)
						if(k==j)
							memo[k][i]=memo[k][i - mon[j]]+1;
						else
							memo[k][i]=memo[k][i - mon[j]];
		}
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	dp();
	for(int te=1;te<=test;te++)
	{
		int x;
		scanf("%d", &x);
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",te, memo[3][x], memo[2][x], memo[1][x], memo[0][x] );
	}
}

