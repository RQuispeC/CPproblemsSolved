#include<bits/stdc++.h>
#define INF 1e9
#define MAX 35
#define fact 9 // si fact > MLE, si fact < WA ( crash en hash function)
using namespace std;
int n, memo[2735][MAX][MAX], dist[MAX][MAX];
int f(int c1, int c2, int c3)
{
	int a[3]={c1,c2,c3};
	sort(a, a+3);
	return a[0]+a[1]*fact+a[2]*fact*fact;//hash function
}
int dp(int c1, int c2, int c3, int city, int lastMove)
{
	int current=f(c1,c2,c3);
	if(city>=n) return 0;
	if(memo[current][city][lastMove]!=-1) return memo[current][city][lastMove];
	int ans=INF;
	ans=min(ans, dp(city+1,c2,c3,city+1, c1));
	ans=min(ans, dp(c1,city+1,c3,city+1, c2));
	ans=min(ans, dp(c1,c2,city+1,city+1, c3));
	return memo[current][city][lastMove]=ans+dist[lastMove][city];
}
int main()
{			
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		memset(memo,-1,sizeof memo);
		memset(dist, 0,sizeof dist);
		scanf("%d",&n);
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int d;
				scanf("%d", &d);
				dist[i][j]=dist[j][i]=d;
			}
		}
		printf("%d\n", dp(0,0,0,0,0));
	}	
}

