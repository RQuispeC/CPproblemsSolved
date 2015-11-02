#include<bits/stdc++.h>
#define MAX 110
using namespace std;
typedef vector < int > vi;
int grip[MAX][MAX], a[MAX][MAX];
bool visited[MAX][MAX];
int r, c, m , n, w;
int even, odd; //par , impar
bool valid(int i , int j)
{
	return i>=0 && j>=0 && i<r && j<c;
}
void dfs(int i, int j, int dx[], int dy[])
{
	visited[i][j]=1;
	for(int k=0;k<8;k++)
	{
		int ni=i+dy[k], nj=j+dx[k];
		if(valid(ni, nj))
		{
			if(!visited[ni][nj] && grip[ni][nj])
				dfs(ni, nj, dx, dy);
		}	
	}
}
void count(int dx[], int dy[])
{
	even=odd=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		{
			if(visited[i][j])
			{
				int cont=0;
				for(int k=0;k<8;k++)
				{
					int ni=i+dy[k], nj=j+dx[k];
					if(valid(ni,nj)  && visited[ni][nj]  && grip[ni][nj] )
					{
						visited[ni][nj]=0;
						cont++;
					}
					
				}
				for(int k=0;k<8;k++)
				{
					int ni=i+dy[k], nj=j+dx[k];
					if(valid(ni,nj)  && !visited[ni][nj]  && grip[ni][nj] )
						visited[ni][nj]=1;
				}
				if(grip[i][j] )
				{
					a[i][j]=cont;
					if(a[i][j]%2==0)
						even++;
					else
						odd++;
				}
			}
		}
}
int main()
{
	int tested;
	scanf("%d", &tested);
	for(int cas=1;cas<=tested;cas++)
	{
		scanf("%d %d %d %d", &r, &c, &m ,&n);
		int dx[8]={m, m, -m, -m, n, -n, n, -n};
		int dy[8]={n, -n, n, -n, m, m, -m, -m};
		memset(grip, 1, sizeof grip);
		memset(a, 0, sizeof a);
		scanf("%d", &w);
		for(int k=0;k<w;k++)
		{
			int i, j;
			scanf("%d %d", &i, &j);
			grip[i][j]=0;
		}
		memset(visited , 0, sizeof visited);
		dfs(0,0, dx, dy);
		count( dx, dy);
		printf("Case %d: %d %d\n", cas, even, odd);	
	}
}

