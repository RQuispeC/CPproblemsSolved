#include <bits/stdc++.h>
#define MAX 55
using namespace std;
int a[MAX][MAX],n , m, memo[MAX][MAX];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
bool valid(int i, int j)
{
	return i>=0 && j>=0 && i<n && j<m;
}
bool isEnd(int i, int j)
{
	for(int k=0;k<4;k++)
	{
		int ni=i+dx[k];
		int nj=j+dy[k];
		if(valid(ni, nj) && a[ni][nj] < a[i][j] )
			return 0;
	}
	return 1;
}
bool isBegin(int i, int j)
{
	for(int k=0;k<4;k++)
	{
		int ni=i+dx[k];
		int nj=j+dy[k];
		if(valid(ni, nj) && a[ni][nj] > a[i][j] )
			return 0;
	}
	return 1;
}
int dp(int i, int j)
{
	if(isEnd(i, j)) return 1;
	if(memo[i][j] != -1 ) return memo[i][j];
	int ans=0;
	for(int k=0;k<4;k++)
	{
		int ni=i+dx[k];
		int nj=j+dy[k];
		if(valid(ni, nj) && a[ni][nj]  < a[i][j] )
			ans+=dp(ni, nj);
	}
	return memo[i][j]=ans;
}
int main()
{
	int test;
	scanf("%d", &test);
	for(int t=1;t<=test;t++)
	{
		memset(memo, -1, sizeof memo);
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(isBegin(i, j))
				{
					ans+=dp(i,j);
				}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
