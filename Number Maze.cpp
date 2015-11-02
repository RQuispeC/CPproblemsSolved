#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdio>
#define MAX 1005
#define INF 10000000000
using namespace std;
struct node
{
	int r, l , c;
	node(){}
	node(int right, int left, int cost)
	{
		r=right;
		l=left;
		c=cost;
	}
	bool operator < ( node x ) const
	{
		return c>x.c;
	}
};
int cases,fil,col;
int A[MAX][MAX];
long long  dist[MAX][MAX];
bool visited [MAX][MAX];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool valid(int i, int j)
{
	return i>=0 && j>=0 && i<fil && j<col;
}
void dijkstra()
{
	dist[0][0]=A[0][0];
	priority_queue  < node > cola;
	cola.push(node(0,0,A[0][0]));
	int it=1;
	while(!cola.empty())
	{
		if(visited[col-1][fil-1]) break;		
		//cout<<"iter :  "<<it++<<endl;	
		node t=cola.top();
		cola.pop();
		visited[t.r][t.l]=true;
		//cout<<t.r<<  "  :  "<<t.l<<endl;
		for(int i=0;i<4;i++)
		{
			int nr=t.r+dy[i];
			int nl=t.l+dx[i];
			if(valid(nr, nl) && !visited[nr][nl] )
			{
				if( (dist[nr][nl] > t.c+A[nr][nl]))
				{
					dist[nr][nl]=t.c+A[nr][nl];
					cola.push(node(nr, nl, dist[nr][ nl]));
				}
			}
		}
	}
}
int main()
{
	scanf("%d", & cases);
	while(cases--)
	{
		scanf("%d %d" , &fil, &col);
		for(int i=0;i<fil;i++)
			for(int j=0;j<col;j++)
				scanf("%d", &A[i][j]);
		memset(visited, false, sizeof (visited));
		for(int i=0;i<MAX;i++)
			for(int j=0;j<MAX;j++)
				dist[i][j]=INF;
		dijkstra();
		cout<<dist[fil-1][col-1]<<endl;
		//cout<<"------------------0"<<endl;
		
		
	}
}

