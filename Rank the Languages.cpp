#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
#define MAX 100
using namespace std;
int filas,columnas;
vector <string > v;
bool visited[MAX][MAX];
int x[]={1,0,-1,0};
int y[]={0,1,0,-1};
int valitade(int i, int j)
{
	return (i>=0 && j>=0 && i<filas && j<columnas);
}
int dfs(int i ,int j)
{
	visited[i][j]=true;
	int cont=0;
	for(int k=0;k<4;k++)
	{
		int nX=i+x[k];
		int nY=j+y[k];
		if(valitade(nX,nY) && v[i][j]==v[nX][nY] && !visited[nX][nY])
			cont+=1+dfs(nX,nY);
	}
	return cont;
}
bool orden(pair < char, int > a, pair < char, int > b)
{
	return a.second>b.second || (a.second==b.second && a.first<b.first);
}
int main()
{
	int tested;
	cin>>tested;
	int p=0;
	while(tested--)
	{
		v.clear();
		memset(visited,false,sizeof(visited));
		cin>>filas>>columnas;
		for(int i=0;i<filas;i++)
		{
			string aux;
			cin>>aux;
			v.push_back(aux);
		}
		vector < pair < char, int > > ans;
		map<char,int > m;
		int h=1;
		ans.clear();
		for(int i=0;i<filas;i++)
		{
			for(int j=0;j<columnas;j++)
			{
				if(!visited[i][j])
				{
					int  l= dfs(i,j);
					if(m[ v[i][j] ] == 0)
					{
						ans.push_back( make_pair(v[i][j],1));
						m[v[i][j]]=h++;
					}
					else
					{
						ans[m[v[i][j]]-1].second+=1;
					}		
				}
			}
		}
		sort(ans.begin(),ans.end(),orden);
		cout<<"World #"<<++p<<endl;
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i].first<<": "<<ans[i].second<<endl;
		}	
	}
	return 0;
}
