#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
int n ,k;
char a[MAX][MAX];
int dis[MAX][MAX];
bool visited[MAX][MAX];
struct node
{
	int i,j, di;
	node(){}
	node(int x, int y, int d)
	{
		i=x;
		j=y;
		di=d;
	}
	bool operator < (node x) const
	{
		return di>=x.di;
	}
};
int dx[4]={0, 1,0, -1};
int dy[4]={1, 0,-1, 0};
bool valid(int i, int j)
{
	return i>=0 && j>=0 && i<n && j<n;
}
void diks()
{
	a[0][0]=='#'?dis[0][0]=1:dis[0][0]=0;
	priority_queue < node > cola;
	cola.push(node(0,0,dis[0][0]));
	visited[0][0]=1;
	while(!cola.empty())
	{
		node t=cola.top();
		cola.pop();
		//cout<<t.i<<" "<<t.j<<" : "<<endl;	
		for(int i=0;i<4;i++)
		{
			int nx=t.i+dx[i], ny=t.j+dy[i];
			
			if(valid(nx, ny) && !visited[nx][ny])
			{
			//cout<<nx<<" "<<ny<<endl;
				visited[nx][ny]=1;
				if(a[nx][ny]=='#')
					dis[nx][ny]=min(dis[nx][ny], t.di+1);
				else
					dis[nx][ny]=min(dis[nx][ny], t.di);	
				cola.push(node(nx, ny, dis[nx][ny]));		
			}
		}
	}	
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		scanf("%d %d", &n, &k );
		memset(a, '.', sizeof a);
		memset(visited, false, sizeof visited);
		//memset(dis, 1000, sizeof dis);
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
				dis[i][j]=dis[j][i]=1000000000;
		}
		for(int i=0;i<k;i++)
		{
			int  u, v;
			scanf("%d %d", &u, &v);
			u--;v--;
			a[u][v]='#';
		}
		diks();
		printf("%d\n", dis[n-1][n-1]);
	}

}

