#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#define INF 10000
using namespace std;
//http://www.spoj.com/problems/CLEANRBT/
int dp[400][400];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
bool visited[20][20];
int f,c, li;
string a[20];
int dist[20][20];
int clean[400];
bool valid(int i, int j)
{
	return i>=0 && j>=0 && i<f && j<c;
}
void bfs(int x, int y)
{
	for(int i=0;i<f;i++)
		for(int j=0;j<c;j++)
			dist[i][j]=INF;
	memset(visited, false, sizeof visited);
	queue < pair < int , pair < int ,  int > > >  cola;
	cola.push(make_pair (0, make_pair(x, y) ));
	while(!cola.empty())
	{
		pair < int , pair < int , int > > t;
		t=cola.front();
		visited[t.second.first][t.second.second]=true;
		dist[t.second.first][t.second.second]=t.first;
		cola.pop();
		for(int i=0;i<4;i++)
		{
			int nx=t.second.first+dx[i];
			int ny=t.second.second+dy[i];
			if(valid(nx, ny) && !visited [nx][ny] && a[nx][ny]!='x')
			{
				int dis=min(dist[nx][ny], t.first+1);
				cola.push(make_pair(dis, make_pair (nx, ny)));
			}
		}
	}
}
int fu(int x , int acu , int ans)
{
	if(acu==li) return  ans;
	int tp=INF;
	int pos=-1;
	clean[x]=true;
	for(int i=0;i<li;i++)
	{
		if(dp[x][i]<tp && i!=x && !clean[i])
		{
			tp=dp[x][i];
			pos=i;
		}
	}
	return fu(pos , acu+1 , ans+ tp);	
}
int main()
{
	vector < pair< int , int > > points;
	while(cin>>c>>f)
	{
		if(f<=0 && c<=0) break;
		for(int i=0;i<f;i++)
			cin>>a[i];
		points.clear();
		points.push_back(make_pair( -1 ,  -1));
		for(int i=0;i<f;i++)
			for(int j=0;j<c;j++)
			{
				if(a[i][j]=='o') points[0]=make_pair(i,j);
				else if(a[i][j]=='*')	points.push_back(make_pair(i,j));
			}	
		li=points.size();	
		bool flag=true;	
		bfs(points[0].first, points[0].second);
		for(int i=1;i<points.size();i++)
		{
			if(dist[points[i].first][points[i].second]==INF)
			{
				flag=false;
				break;
			}
			dp[0][i]=dist[points[i].first][points[i].second];
			dp[i][0]=dp[0][i];	
		}
		if(!flag)
			cout<<-1<<endl;
		else
		{
			//leeeeeeeeeeeeeeeeeeeeeento	
			for(int i=0;i<li && flag;i++)
			{
				bfs(points[i].first, points[i].second);
				for(int j=i;j<li && flag;j++)
				{
					if(i==0 && dist[points[j].first][points[j].second]==INF)
					{
						flag=false;
					}
					dp[i][j]=dist[points[j].first][points[j].second];
					dp[j][i]=dp[i][j];
				}
				clean[i]=false;	
			}
		//leeeeeeeeeeeeeeeeeeeeeento
			int ans=fu(0, 1, 0 );		
			cout<<ans<<endl;
		}							
	}
}
/*
-1
8
49
6
----NPI
10 10
..........
..o.......
..........
..........
..........
.....xxxxx
.....x....
.....x.*..
.....x....
.....x....
7 5
.......
.o...*.
.......
.*...*.
.......
15 13
.......x.......
...o...x....*..
.......x.......
.......x.......
.......x.......
...............
xxxxx.....xxxxx
...............
.......x.......
.......x.......
.......x.......
..*....x....*..
.......x.......
4 4
....
.x*.
.xx.
o...
20 20
********************
********************
********************
********************
********************
********************
********************
********************
********************
*********o**********
********************
********************
********************
********************
********************
********************
********************
********************
********************
********************
********************
0 0
*/
