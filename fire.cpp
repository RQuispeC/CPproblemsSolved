#include<bits/stdc++.h>
#define INF 1<<30
#define MAX 100
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef pair< int , pii > piii;
typedef vector < pii > vii;
typedef long long ll;
vector < vector < string > > grip;
int L, n, m, N, timee; 
struct person
{
	int i, j, l , win;
	person(){}
	person(int  _l, int _i, int _j, int w)
	{
		l=_l;
		i=_i;
		j=_j;
		win=w;
	}
};
int dx[4]={0, 1, -1, 0};
int dy[4]={1, 0, 0, -1};
person a[105];
bool vis[15][105][105];
int dis[15][105][105];
bool valid(int i, int j, int lev)
{
	return i>=0 && j>=0 && i<n && j<m && grip[lev][i][j]!='X';
}
void bfs(int _i, int _j, int _l)
{
	memset(vis, 0,sizeof vis);
	memset(dis, -1, sizeof dis);
	queue < piii > q;
	q.push(piii(_l, pii(_i, _j)));
	dis[_l][_i][_j]=0;
	while(!q.empty())
	{
		piii u= q.front();
		q.pop();
		vis[u.first][u.second.first][u.second.second] =1;
		//cout<<u.first<<" "<<u.second.first<<" "<<u.second.second<<endl;
		for(int k=0;k<4;k++)
		{
			//cout<<"en"<<endl;
			int ni=u.second.first + dy[k];
			int nj=u.second.second + dx[k];
			if(valid(ni, nj,u.first) && !vis[u.first][ni][nj])
			{
	//			cout<<"em2"<<endl;
				q.push(piii(u.first, pii(ni,nj)));
				vis[u.first][ni][nj] =1;
				dis[u.first][ni][nj] = dis[u.first][u.second.first][u.second.second] +1;
			}
		}
		//cout<<"pasasd"<<endl;
		if(grip[u.first][u.second.first][u.second.second]=='U')
		{
			//cout<<"em3"<<endl;
			q.push(piii(u.first+1,pii( u.second.first,u.second.second)));
			vis[u.first+1][u.second.first][u.second.second]=1;
			dis[u.first+1][u.second.first][u.second.second] = dis[u.first][u.second.first][u.second.second] +1;
		}
		//cout<<"pasasd"<<endl;
	}
}
int cost[MAX], get[MAX];
int memo[105][10005];
int dp(int pos, int rem)
{
	if(pos==N || rem==0) return 0;
	if(memo[pos][rem] != -1 ) return memo[pos][rem];
	int ans=0;
	if(rem >= cost[pos])
		ans=max(dp(pos+1, rem), get[pos]+ dp(pos+1, rem - cost[pos]));
	else
		ans=dp(pos+1, rem);
	return memo[pos][rem]=ans;	
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d %d %d %d %d", &L, &n, &m, &N, &timee);
		grip=vector < vector< string> > (L, vector< string > (n));
		for(int i=0;i<L;i++)
			for(int j=0;j<n;j++)
				cin>>grip[i][j];
		/*for(int i=0;i<l;i++)
			for(int j=0;j<n;j++)
				cout<<grip[i][j]<<endl;*/
		for(int i=0;i<N;i++)
		{
			int _l, _i, _j, _w;
			scanf("%d %d %d %d", &_l, &_i, &_j, &_w);
			_l--, _i--, _j--;
			//cout<<_l<<" "<<_i<<" "<<_j<<"  "<<_w<<endl;
			a[i]=person(_l, _i, _j, _w);
		}
		int ibeg, jbeg;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(grip[0][i][j]=='S') 
				{
					ibeg=i;
					jbeg=j;
				}
		bfs(ibeg, jbeg, 0);
		for(int i=0;i<N;i++)
		{
			cost[i]=dis[a[i].l][a[i].i][a[i].j]*3;
			get[i]=a[i].win;
			cout<<" --> "<<cost[i]/3<<endl;
		}
		memset(memo, -1, sizeof memo);
		printf("%d\n", dp(0, timee));
	}
}
