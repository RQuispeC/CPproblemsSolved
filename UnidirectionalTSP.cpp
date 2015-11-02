#include<bits/stdc++.h>
#define INF (1<<30) + 100
using namespace std;
int memo[20][110], n, m, a[20][110];
vector < int  > path;
int dp(int row, int column)
{
	if(column==n) return 0;
	if(memo[row][column]!= INF ) return memo[row][column];
	int ans=INF;
	for(int i=-1;i<=1;i++)
		ans=min(ans, dp ((row+i+m)%m, column+1) + a[row][column]);
	return memo[row][column]=ans;
}
void f(int i, int j)
{
	if(j==n) return;
	path.push_back(i+1);
	int ans=INF;
	int posibles[3];
	for(int k=-1;k<=1;k++)
	{
		posibles[k+1]=(i+k+m)%m;
		ans=min(ans, memo [(i+k+m)%m][ j+1]);
	}
	sort(posibles, posibles+3);
	for(int k=0;k<3;k++)
		if(memo[ posibles[k] ] [j+1] == ans)
		{
			
			f(posibles[k],j+1);
			break;
		}
}
int main()
{
	//cout<<INF<<endl;
	while(cin>>m>>n)
	{
		
		path.clear();
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
				memo[i][j]=INF;
			}
		int ans=INF;
		for(int i=0;i<m;i++)
		{	
			ans=min(ans, dp(i,0));
		}	
		for(int i=0;i<m;i++)
		{	
			if(memo[i][0]==ans)
			{
				f(i,0);
				break;
			}	
		}
		for(int i=0;i<n;i++)
		{
			cout<<path[i];
			if(i+1<n)
				cout<<" ";
		}			
		cout<<endl<<ans<<endl;	
	}
}

