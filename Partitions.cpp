#include<bits/stdc++.h>
#define MAX 3005
using namespace std;
char grip[MAX][MAX];
int n;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
//bool vis[MAX][MAX];
bool validate(int i, int j)
{
	return  i>=0 && j>=0 && i<n && j<n;
}
void dfs(int i, int j)
{
	grip[i][j]='2';
	for(int k=0;k<4;k++)
	{
		int ni=i+dy[k], nj=j+dx[k];
		if(validate(ni,nj) )
			if( grip[ni][nj]=='0')
				dfs(ni,nj);
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grip[i][j];
		}	
	}
	//memset(vis, 0, sizeof vis);
	int ans=0;
	//cout<<"pas" << n<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(grip[i][j]=='0')
			{
		//		cout<<i<<" : "<<j<<endl;
				ans++;
				dfs(i,j);
			}
		}
	}
	//cout<<"pas"<<endl;
	cout <<ans<<endl;
}

