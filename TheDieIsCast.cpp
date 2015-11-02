#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 55
using namespace std;
struct point
{
	int i, j;
	point( int y, int x)
	{
		i=y;
		j=x;
	}
	point ()
	{
		i=0;
		j=0;
	}
};
int fil, col;
vector < string > a;
int visited [MAX][MAX]; // 0 no visited, 1 visted *, 2 visted X
bool visitedX [MAX][MAX];
int dx[4]={0,1,0,-1 };
int dy[4]={1,0,-1,0 };
bool validate( int i, int j)
{
	return i>=0 && j>=0 && i<fil && j<col;
}
int dfs(int i, int j)
{
	visitedX[i][j]=true;
	int k=1;
	for(int t=0;t<4;t++)
	{
		int ni=i+dy[t];
		int nj=j+dx[t];
		if(validate(ni, nj)  && !visitedX[ni][nj] && a[ni][nj]=='X' ) 
			k+=dfs(ni,nj);
	}
	return k;
}
vector < point > temp;
void DFS( int i, int j )
{
	if(a[i][j]=='X')
	{
		visited[i][j]=2;
		//cout<<"pusj"<<i<<"  "<<j<<" :   "<<visited[i][j]<<endl; 
		temp.push_back(point (i, j));
	}	
	if(a[i][j]=='*') visited[i][j]=1;
	for(int t=0;t<4;t++)
	{
		int ni=i+dy[t];
		int nj=j+dx[t];
		if(validate(ni, nj)  && visited[ni][nj]==0 ) 
			if( a[ni][nj]=='X' || a[ni][nj]== '*' ) 
			{
				//cout<<"en  >>>>  :  "<<ni<<"  "<<nj<<endl;
				DFS(ni,nj);
			}
	}
}	 
int main()
{
	int throws=1;
	while(cin>>col>>fil)
	{
		if(col==0 && fil==0)  break;
		cout<<"Throw "<<throws++<<endl;
		a.clear();
		memset( visited, 0, sizeof visited);
		memset( visitedX, false, sizeof visitedX);
		for(int i=0;i<fil;i++)
		{
			string aux;
			cin>>aux;
			a.push_back(aux);
		}	
		vector < int > ans;
		ans.clear();
		for(int i=0;i<fil;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(a[i][j]=='*' && visited[i][j]==0 )
				{
					temp.clear();
					//cout<<"en  >>>>  :  "<<i<<"  "<<j<<endl;
					DFS(i, j);
					int ansDice=temp.size();
					//cout<<"pos:   "<<ansDice<<endl;
					for(int ca=0;ca<temp.size();ca++)
					{
						int aux=dfs(temp[ca].i , temp[ca].j);
						//cout<<">>  "<<temp[ca].i<<"  "<<temp[ca].j<<" :  "<<aux<<endl;
						aux--;
						ansDice-=aux;
					}
					ans.push_back(ansDice);	
				}	
			}	
		}

		sort(ans.begin(), ans.end());
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i];
			if(i<ans.size()-1) cout<<" ";
		}
		cout<<endl;
							
	}
}

