#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
string a [505];
bool visited [505][505];
int n, m , iniI,iniJ;
vector < pair < int, int > > r; 
vector < pair < int, int > > b;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool valid( int i, int j)
{
	return i>=0 && j>=0 && i<n && j<m; 
}
void dfs(int i,int j)
{
	visited[i][j]= true;
	b.push_back( make_pair ( i,j ));
	for(int k=0;k<4;k++)
	{
		int ni=i+dy[k];
		int nj=j+dx[k];
		if(valid(ni,nj) && a[ni][nj]=='.' && !visited[ni][nj])
			dfs(ni,nj);
	}
	if(!(i==iniI && j==iniJ) )
		r.push_back(make_pair (i,j));
}

int main()
{
	memset(visited, false, sizeof visited);
	r.clear();
	b.clear();
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='.' && !visited[i][j])
			{
				iniI=i;
				iniJ=j;
				dfs(i,j);
			}
		}
	cout<<b.size()+2*r.size()<<endl;
	char op='B';
	for(int i=0;i<b.size();i++)
		printf("%c %d %d\n", op,b[i].first+1,b[i].second+1);
	char op2='R';
	op='D';	
	for(int i=0;i<r.size();i++)
	{
		printf("%c %d %d\n", op,r[i].first+1,r[i].second+1);
		printf("%c %d %d\n", op2,r[i].first+1,r[i].second+1);
	}
}
