#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 24 
using namespace std;
vector < string > a;
bool visitados[MAX][MAX];
int n;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
bool validate(int fi, int co)
{
	return fi>=0 && co>=0 && fi<n && co<n;
}
int dfs(int fi, int co){
	visitados[fi][co] = true;
	int k  = 1;
	for(int i = 0; i < 4; i++){
		int nf = fi + dy[i];
		int nc = co + dx[i];		
		if(validate(nf,nc) &&  a[fi][co]==a[nf][nc] && !visitados[nf][nc])
		{
			k += dfs(nf,nc);
		}
	}	
	return k;
}
int main()
{
	int tested;
	cin>>tested;
	for(int t=1;t<=tested;t++)
	{
		cout<<"Case #"<<t<<": ";
		a.clear();
		memset(visitados,false,sizeof(visitados));
		cin>>n;
		for(int i=0;i<n;i++)
		{
			string aux;
			cin>>aux;
			a.push_back(aux);
		}	
		vector < pair< int, pair < int, int > > > ans;
		ans.clear();
		for(int i=0;i<n;i++)
			for(int j=0 ;j<n;j++)
				if(!visitados[i][j] && a[i][j]=='#')
					ans.push_back(make_pair(dfs(i,j), make_pair(i,j)));
		if(ans.size()>1)
			cout<<"NO"<<endl;
		else
		{
			int aux=(int) sqrt(ans[0].first);
			if(aux*aux!= ans[0].first)
				cout<<"NO"<<endl;
			else
			{
				int x=ans[0].second.first;
				int y=ans[0].second.second;
				bool flag=true;
				for(int i=x;i<x+aux && flag;i++)
					for(int j=y;j<y+aux && flag;j++)
						if(a[i][j]=='.') flag=false;
				if(flag) 	
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}			
		}	
	}
}
