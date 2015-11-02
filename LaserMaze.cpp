#include <bits/stdc++.h>
#define MAX 105
using namespace std;
typedef pair < int , int  > pii;
typedef pair < pii, int > piii;
typedef vector <  int > vi;
typedef vector < pii > vii;
int n , m;
vii data;//[0]= begin,[1]=end, laser pos. 
vector < string > grip;
bool vis[MAX][MAX][4];
char graph[MAX][MAX][4];
int d[MAX][MAX][4];
int dc[4]={'<','^','>','v'};
int dy[4]={0, -1, 0, 1};// (i) row
int dx[4]={-1, 0, 1, 0};// (j) column
char fun( char lazer)
{
	int pos=-1;
	for(int i=0;i<4;i++)
		if(lazer==dc[i])
		{
			pos=i;
			break;
		}
	return dc[(pos+1)%4];
}
int getDir( char lazer)
{
	for(int i=0;i<4;i++)
		if(lazer==dc[i])
			return i;
	return -1;		
}
bool validDisp(int i, int j, int k)
{
	return i>=0 && j>=0 && i<n && j<m && (graph[i][j][k]=='.' || graph[i][j][k]=='x') ;
}
bool validMov(int i, int j, int k)
{
	return i>=0 && j>=0 && i<n && j<m && graph[i][j][k]=='.';
}
void getGraph()
{
	data.assign(2, pii(-1,-1));
	for(int i=0;i < n;i++)
		for(int j=0;j<m;j++)
		{
			if(grip[i][j]=='S')
			{
				data[0]=pii(i,j);
				graph[i][j][0]=graph[i][j][1]=graph[i][j][2]=graph[i][j][3] ='.';
			}	
			else if(grip[i][j]=='G')
			{
				data[1]=pii(i,j);
				graph[i][j][0]=graph[i][j][1]=graph[i][j][2]=graph[i][j][3] ='.';	
			}	
			else
			{ 
				graph[i][j][0]=graph[i][j][1]=graph[i][j][2]=graph[i][j][3] =grip[i][j];
				if(getDir(graph[i][j][0])>=0)
				{
					data.push_back(pii(i,j));
					graph[i][j][1] = fun(graph[i][j][0]);
					graph[i][j][2] = fun(graph[i][j][1]);
					graph[i][j][3] = fun(graph[i][j][2]);
				}	
			}		
		}
	for(int i=2;i<data.size();i++)
	{	
		int dire=getDir(graph[data[i].first][data[i].second][0]);
		for(int k=0;k<4;k++)
		{
			 int dir=(dire+k)%4;
			 int ni=data[i].first+dy[dir];
			 int nj=data[i].second+dx[dir];
			 while(validDisp(ni,nj,k) )
			 {
			 	graph[ni][nj][k]='x';
			 	ni+=dy[dir];
			 	nj+=dx[dir];
			 }
		}
	}
}
void sol(piii ini)
{
	memset(d, -1, sizeof d);
	memset(vis, 0, sizeof vis);
	d[ini.first.first][ini.first.second][ini.second] = 0 ;
	queue < piii > q;
	q.push(ini);
	while(!q.empty())
	{
		piii u=q.front();
		q.pop();
		vis[u.first.first][u.first.second][u.second]=1;
		if(u.first.first==data[1].first && u.first.second==data[1].second) break;
		for(int k=0;k<4;k++)
		{
			int ni=u.first.first + dy[k];
			int nj=u.first.second + dx[k];
			int nl=(u.second + 1 ) %4;
			if(validMov(ni, nj, nl) && !vis[ni][nj][nl])
			{
				vis[ni][nj][nl]=1;
				q.push(piii(pii(ni, nj), nl));
				d[ni][nj][nl]=d[u.first.first][u.first.second][u.second] + 1;
			}
		}
	}
	
}
int main()
{
	int test;
	scanf("%d", &test);
	for(int te=1;te<=test;te++)
	{
		grip.clear();
		data.clear();
		scanf("%d %d", &n, &m);
		for(int i=0;i<n;i++)
		{
			string x;
			cin>>x;
			grip.push_back(x);
		}
		getGraph();
		sol(piii(pii(data[0].first, data[0].second),0));
		int pos=-1;
		for(int i=0;i<4;i++)
			if(d[data[1].first][data[1].second][i] !=-1)
			{
				pos=i;
				break;
			}
		if(pos>=0)
			printf("Case #%d: %d\n", te,d[data[1].first][data[1].second][pos]);
		else
			printf("Case #%d: impossible\n", te);
	}
}
