#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 110
using namespace std;
int kingdom [MAX][MAX];
int war [MAX][MAX];
int n, r,c, k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool valid (int i ,int j)
{
	return i>=0 && j>=0 && i<r && j<c;
}
void atack(int i, int j)
{
	for(int t=0;t<4;t++)
	{
		int ni=i+dy[t];
		int nj=j+dx[t];
		if(valid(ni,nj) && kingdom[ni][nj] == ( kingdom[i][j]+ 1) %n)
			war[ni][nj]=kingdom[i][j];
	}
}
void fight()
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			atack(i,j);		
		}
	}
	//actualizar KINGDOM
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			kingdom[i][j]=war[i][j];		
		}
	}
}
int main()
{
	while(cin>>n>>r>>c>>k)
	{
		if(n==0 && r==0 && c==0 && k==0) break;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				cin>>kingdom[i][j];
				war[i][j]=kingdom[i][j];
			}
				
		for(int t=0;t<k;t++)
			fight();
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cout<<kingdom[i][j];
				if(j<c-1) cout<<" ";
			}
			cout<<endl;	
		}
	}
}

