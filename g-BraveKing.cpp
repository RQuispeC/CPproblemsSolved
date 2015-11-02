#include<bits/stdc++.h>
#define MAX 110
#define INF 1e9
using namespace std;
string a[MAX];
int n, m, memo[MAX][MAX];
int dx[3]={1,0,0};
int dy[3]={0,1,-1};
bool visited[MAX][MAX];
struct node
{
	int i, j ,w;
	node(){}
	node(int y, int x, int we)
	{
		i=y, j=x, w=we;
	}
	bool operator < ( node x) const
	{
		return w<x.w;
	}
};
bool valid (int i, int j)
{
	return i>=0 && j>=0  && i<n && j<m;
}
bool isAtacked(int i, int j)
{
	int i1=i-1, j1=j-1;
	int i2=i-1, j2=j+1;
	if(valid (i1, j1) && a[i1][j1]=='1')
		return true;
	if(valid (i2, j2) && a[i2][j2]=='1')
		return true;
	return false;	
}
int dp(int i, int j)
{
	visited[i][j]=1;
	//cout<<i<<" : "<<j<<endl;
	if(j==m-1) return 0;	
	if(memo[i][j] == -2) return INF;
	if(memo[i][j] != -1) return memo[i][j];
	int ans=INF;
	bool flag=false;
	for(int k=0;k<3;k++)
	{
		int ni=i+dy[k];
		int nj=j+dx[k];
		if(valid (ni, nj) && ! isAtacked(ni,nj) && ! visited[ni][nj])
		{
			flag=true;
			if(a[ni][nj] == '1' )
			{
				//cout<<"come"<<endl;
				ans=min(ans, dp (ni,nj)+1);
			}	
			else
				ans=min(ans, dp (ni,nj));
		}
	}
	if(flag && ans!=INF)
		return memo[i][j]=ans;
	else
		return memo[i][j]=-2;	
}
int dij(int i, int j)
{
	int ans=INF;
	visited[i][j]=1;
	priority_queue < node  > q;
	q.push(node(i,j,0));
	while(!q.empty())
	{	
		node u=q.top();
		q.pop();
		for(int k=0;k<3;k++)
		{
			int ni=u.i+dy[k];
			int nj=u.j+dx[k];
			if(valid (ni, nj) && !isAtacked(ni,nj) && !visited[ni][nj])
			{
				visited[ni][nj]=1;
				if(a[ni][nj]=='1')
					q.push(node(ni, nj, u.w+1));
				else
					q.push(node(ni, nj, u.w));	
			}
		}
		if(u.j== m-1) 
			ans=min(ans, u.w);
	}
	if(ans == INF) 
		return -1;
	return ans;	
}
int main()
{
	int cas=1;
	while(cin>>n>>m)
	{
		if(n==0 && m==0 ) break;
		for(int i=0;i<n;i++)
			cin>>a[i];
		memset(memo , -1, sizeof memo);
		memset(visited, 0, sizeof visited);
		int ans=dij(n-1, 0);
		//cout<<"pas: "<<ans<<endl;	
		cout<<"Case "<<cas++<<": ";
		if(ans<0)
			cout<<"Impossible"<<endl;
		else
			cout<<ans<<endl;
	}
}

