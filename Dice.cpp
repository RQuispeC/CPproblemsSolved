#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#define MAX 105
using namespace std;
double dp[MAX][MAX];
int main()
{
	memset(dp, 0ll, sizeof dp);
	for(long long i=1;i<=6;i++)
		dp[1][i]=1;	
	for(int i=2;i<=MAX;i++)
	{
		for(int j=i;j<=MAX;j++)
		{
			if(i==j) dp[i][j]=(double)1;
			else
			{
				double  ans=(double )0;
				for(int k=6;k>=1 ;k--)
				{
					if(j-k>=0)
					ans+=dp[i-1][j-k];
				}				
				dp[i][j]=ans;	
			}
		}
	}
	/*for(int i=1;i<MAX;i++)
	{
		for(int j=1;j<MAX;j++)
			cout<<dp[i][j]<<"  ";
		cout<<endl;	
	}*/
	int tested;
	cin>>tested;
	while(tested--)
	{
		int  n, m;
		cin>>n>>m;
		double num=(double)dp[n][m];
		//cout<<num<<endl;
		double den=pow(6,n);
		//cout<<den<<endl;
		printf("%.2f\n", num/den);
	}
	
}

