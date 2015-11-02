#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;
struct point 
{
	int i,j, dist;
	point()
	{
		i=j=-1;
		dist=0;
	}
	point( int y, int x, int d)
	{
		i=y;
		j=x;
		dist=d;
	}
};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int r,c;
bool map [1005][1005];
bool visited [1005][1005];
bool validate( point p)
{
	return p.i>=0 && p.j>=0 && p.i<r && p.j<c;
}
void bfs(point ini , point goal)
{
	queue < point > cola;
	cola.push(ini);
	map[ini.i][ini.j]=true;
	while(!cola.empty())
	{
		point p=cola.front();
		if(p.i==goal.i && p.j==goal.j)
		{
			printf("%d\n", p.dist);
		}
		cola.pop();
		for(int i=0; i<4 ;i++)
		{
			point next= point(p.i+dy[i],p.j+dx[i], p.dist+1);
			if( validate( next ) && !visited [next.i][next.j] && !map[next.i][next.j])
			{
				visited[next.i][next.j]=true;
				cola.push(next);
			}
		}	
	}
}
int main()
{
	while(scanf("%d %d", &r, &c))
	{
		if(r==0 && c==0 )  break;
		memset(map , false, sizeof map);
		memset(visited, false, sizeof visited);
		int bomb;
		scanf("%d" , &bomb);
		for(int i=0;i<bomb;i++)
		{
			int row, num;
			scanf("%d %d" , &row, &num);
			for(int i=0;i<num;i++)
			{
				int col;
				scanf("%d",&col );
				map[row][col]=true;
			}			
		}
		int xi,yi,xf,yf;
		scanf("%d %d", &yi,& xi);
		scanf("%d %d", &yf,& xf);
		bfs(point(yi,xi,0), point(yf,xf, 0));
	}
}

