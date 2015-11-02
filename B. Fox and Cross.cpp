#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX 110
using namespace std;
int n,cruces;
vector < string > a;
bool visited [MAX][MAX]; 
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
bool valid(int i, int j)
{
	return i>=0 && j>=0 && i<n && j<n;
}
bool cruz(int i, int j)
{
	int cont=0;
	for(int k=0;k<4;k++)
	{
		int ni=i+dy[k];
		int nj=j+dx[k];
		if(valid(ni,nj) && !visited[ni][nj] && a[ni][nj]=='#')
			cont++;
	}
	if(cont==4)//existe una cruz
	{
		visited[i][j]=true;
		for(int k=0;k<4;k++)
		{
			int ni=i+dy[k];
			int nj=j+dx[k];
			visited[ni][nj]=true;
		}
		return true;
	}
	else return false;
	
}
int main()
{
	a.clear();
	memset( visited, false, sizeof visited);
	cin>>n;
	int pos=0;
	for(int i=0;i<n;i++)
	{
		string aux;
		cin>>aux;
		a.push_back(aux);
		for(int i=0;i<n;i++)
			if(aux[i]=='#') pos++;
	}
	if(pos==0 ) cout<<"YES"<<endl;
	else if(pos%5!=0 ) cout<<"NO"<<endl;
	else
	{
		cruces=pos/5;
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(a[i][j]=='#')
				{
					if(cruz(i,j))				
						cruces--;
				}
			}
		}
		if(cruces==0 )cout<<"YES"<<endl;	
		else cout<<"NO"<<endl;
	}
}
