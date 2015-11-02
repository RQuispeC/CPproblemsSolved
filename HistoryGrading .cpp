#include<bits/stdc++.h>
#define MAX 25
using namespace std;
typedef vector < int > vi;
int a[MAX], b[MAX], n;
int memo[MAX][MAX];
int dp()
{
	for(int i=0;i<n;i++)
		memo[i][0]=0;
	for(int i=0;i<n;i++)
		memo[0][i]=0;	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i]==b[j])
				memo[i+1][j+1] = memo[i][j]+1;
			else
				memo[i+1][j+1]=max(memo[i][j+1], memo[i+1][j]);
	return memo[n][n];			
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int pos;
		scanf("%d", &pos);
		a[pos-1]=i+1;
	}
	while(cin>>b[0])
	{
		b[b[0]-1]=1;
		for(int i=1;i<n;i++)
		{
			int pos;
			scanf("%d", &pos);
			b[pos-1]=i+1;
		}	
		printf("%d\n", dp());
	}
		
}

