#include<iostream>
#include<cstring>
#define MAX 1000010
#define MOD 1073741824
using namespace std;
int dp[MAX];
int a,b,c;
int ans=0;
int d(int n)
{
	if(dp[n]!= -1) return dp[n];
	int ans=0;
	for(int i=1;i*i<=n;i++)
	{
		if(i*i==n) ans++;
		else if(n%i==0 ) ans+=2;
	}
	dp[n]=ans%MOD;
	return dp[n];
}
int main()
{
	memset( dp, -1, sizeof dp);
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=1;k<=c;k++)
			{
				ans=ans+d(i*j*k);
				ans=ans % MOD; 
			}
		}
	}
	cout<<ans<<endl;
}

