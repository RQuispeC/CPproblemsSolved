#include<bits/stdc++.h>
#define MAX 1005
#define INF 1e9
using namespace std;
vector < string  > grip;
vector < vector < int >  >  dis;
bool vis[MAX][MAX];
int n , m, ans, fil[MAX], colum[MAX];
void bfs()
{
	vector < int >  aux;
	aux.assign (MAX,  INF);
	memset(vis, 0, sizeof vis);
	dis.assign(MAX, aux);
	queue < pair < int , int >   > q;
	queue < int > lastMove;
	for(int j=0;j<m;j++)
		if(grip[n-1][j] == '#')
		{
			dis[n-1][j] = 0;
			q.push(make_pair (n-1,j));
			lastMove.push(0);
			colum[j]--;
			fil[n-1]--;
		}
	while(!q.empty())
	{
		pair < int, int  > u = q.front();
		int lm=lastMove.front();
		lastMove.pop();
		q.pop();
		vis[u.first][u.second]=1;
		if(u.first == 0  )
		{
			ans=min(ans, dis[u.first][u.second] +1 );
			break;
		}
		if(lm==0 &&  colum[u.second])
		for(int i=0;i<n;i++)
		{
			if(grip[i][u.second]=='#' && ! vis[i][u.second])
			{
				q.push(make_pair(i, u.second));
				lastMove.push(1);
				dis[i][u.second] = dis[u.first][u.second]+1;
				vis[i][u.second]=1;
				colum[u.second]--;
				fil[i]--;								
			}
		}
		if(lm==1 && fil[u.first])
		for(int j=0;j<m;j++)
		{
			if(grip[u.first][j]=='#' && ! vis[u.first][j])
			{
				q.push(make_pair(u.first, j));
				lastMove.push(0);
				dis[u.first][j] = dis[u.first][u.second]+1;
				vis[u.first][j]=1;
				colum[j]--;
				fil[u.first]--;
			}
		}
	}
}
int main()
{
	memset(colum, 0, sizeof colum);
	memset(fil, 0, sizeof  fil);
	grip.clear();
	cin>>n>>m;
	int end=0, begin=0;
	for(int i=0;i<n;i++)
	{
		string aux;
		cin>>aux;
		grip.push_back(aux);
		for(int j=0;j<m;j++)
		{
			if(grip[i][j]=='#')
			{
				if(i==0)
				 	end++;
				if(i==n-1)
					begin++;
				colum[j]++;
				fil[i]++;	
			}
		}
	}
	if(begin==0 || end==0 )
		cout<<-1<<endl;
	else
	{	
		ans=INF;
		bfs();
		if(ans==1 &&  n ==1)
			ans--;
		if(ans==INF)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;		
	}
	
}


