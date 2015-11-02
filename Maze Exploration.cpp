#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAXx 30 
#define MAXy 80
using namespace std;
vector<string> V;
bool visitados[MAXx][MAXy];
int dx[8] = {0,1,0,-1};
int dy[8] = {-1,0,1,0};
bool esValido(int a, int b)
{
	return a>=0 && b>=0;
}
void dfs(int a, int b)
{
	visitados[a][b]=1;
	V[a][b]='#';
	for(int i=0;i<4;i++)
	{
		int na=a+dy[i];
		int nb=b+dx[i];
		if(esValido(a,b) && V[na][nb]==' ' && !visitados[na][nb])
		{	
			dfs(na,nb);			
		}
	}
} 
int main()
{	 
	int n;
	cin>>n;
	string p;
	getline(cin,p);
	while(n--){
		V.clear();
		memset(visitados,0,sizeof(visitados));	
		while(getline(cin,p) && p[0]!='_')
		{
			V.push_back(p);
		}
			
		for(int i=0;i<V.size();i++)
		{			
			for(int j=0;j<V[i].size();j++)
			{
				if(!visitados[i][j] && V[i][j]=='*')
					dfs(i,j);
			}
		}
		for(int i=0;i<V.size();i++)
				cout<<V[i]<<endl;
		cout<<"_____"<<endl;		
	}
	
	return 0;

}
