#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef vector < int > vi;
typedef pair<int , int > pii;
vector < string > grip;
int n, m;
int vis[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool valid(int i, int j)
{
	return i>=0 && j>=0 && i<n && j<m;
}
int sol(int iBeg, int jBeg)
{
	queue < pii > q;
	q.push(pii(iBeg, jBeg));
	pii last;
	while(!q.empty())
	{
		pii u = q.front();
		last=u;
		vis[u.first][u.second] = 1;
		q.pop();
		for(int k=0;k<4;k++)
		{
			int ni = u.first + dx[k];
			int nj = u.second + dy[k];
			if(valid(ni, nj) && vis[ni][nj]==0 && grip[ni][nj]=='.')
			{
				vis[ni][nj]=1;
				q.push(pii(ni, nj));
			}
		}
	}
	q.push(last);
	bool flag=0;
	while(!q.empty())
	{
		pii u = q.front();
		last=u;
		q.pop();
		for(int k=0;k<4;k++)
		{
			int ni = u.first + dx[k];
			int nj = u.second + dy[k];
			if(valid(ni, nj) && vis[ni][nj]==1 && grip[ni][nj]=='.')
			{
				vis[ni][nj]=vis[u.first][u.second] + 1;
				q.push(pii(ni, nj));
			}
		}
		if(!flag) vis[u.first][u.second] = 0;
		flag=1;
	}
	return max(vis[last.first][last.second], 1);
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		grip.clear();
		scanf("%d %d", &n, &m);
		swap(n, m);
		for(int i=0;i<n;i++)
		{
			string tmp;
			cin>>tmp;
			grip.push_back(tmp);
		}
		memset(vis, 0 ,sizeof vis);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(vis[i][j]==0 && grip[i][j]=='.')
					ans= max(ans, sol(i, j));
		printf("Maximum rope length is %d.\n",max(0, ans-1));
	}
}
