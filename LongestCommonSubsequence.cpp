#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
string a, b;
int memo[MAX][MAX];
int dp()
{
	for(int i=0;i<a.size();i++)
		memo[i][0]=0;
	for(int i=0;i<b.size();i++)
		memo[0][i]=0;	
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			if(a[i]==b[j])
				memo[i+1][j+1] = memo[i][j]+1;
			else
				memo[i+1][j+1]=max(memo[i][j+1], memo[i+1][j]);
	return memo[a.size()][b.size()];			
}
int main()
{
	while(getline(cin,a))
	{
		getline(cin,b);
		printf("%d\n", dp());
	}
}

