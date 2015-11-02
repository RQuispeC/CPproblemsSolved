#include<iostream>
#include<cstring>
#define MAX 1000000005//too long
using namespace std;
bool visited [MAX][MAX];
bool planet [MAX][MAX];
int n;
bool valid (int i, int j)
{
	return i>=0 && j>=0 && i<n && j<n && planet[i][j];
}
bool dfs(int i, int j)
{
	if(i==n-1 && j==n-1 ) return true;
	visited [i][j]=true;
	int ni1=i+1;
	int nj1=j;
	int ni2=i;
	int nj2=j+1;
	if(!visited[ni1][nj1] && valid(ni1,nj1) && !visited[ni2][nj2] && valid(ni2,nj2))
		return dfs(ni1,nj1)  || dfs(ni2,nj2);
	else if(!visited[ni1][nj1] && valid(ni1,nj1))
		return dfs(ni1,nj2);
	else if(!visited[ni2][nj2] && valid(ni2,nj2))
		return dfs(ni2,nj2);
	else return false;	
}
int main()
{
	int m;
	cin>>n>>m;
	memset(visited,false, n+5);
	memset(planet,true,n+5);
	bool flag=true;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==n && y==n)
		{
			flag=false;
			break;
		}
		planet [x-1][y-1]=false;
	}
	if(!flag)
		cout<<-1<<endl;
	else
	{	
		bool ans=dfs(0,0);
		if(ans)
			cout<<2*n-2<<endl;
		else
			cout<<-1<<endl;
	}	
}

