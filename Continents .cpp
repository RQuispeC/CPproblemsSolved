#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 20
using namespace std;
char tierra;
bool visitados[MAX][MAX];
vector<string> V;
vector<pair <char,int> > Ans;
int n,m;//m #de filas, n # de columnas 
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
bool esValido(int a, int b)
{
	return a>=0 && b>=0 && a<m && b<n;	
}
int dfs(int a,int b)
{
	visitados[a][b]=1;
	int k=1;
	for(int i=0;i<4;i++)
	{
		int na = a + dy[i];
		int nb = b + dx[i];
		if(nb<0) nb=n-1;
		else nb%=n;
		if(esValido(na,nb) &&  V[a][b]==V[na][nb] && !visitados[na][nb])//verifica si es valido, si el que le sigue el igual y si ya todavia no ha sido visitado
		{
			k += dfs(na,nb);
		}
	}
	return k;
}
int main()
{
	while(cin>>m && cin>>n){
	memset(visitados,0,sizeof(visitados));
	V.clear();
	Ans.clear();
	int x,y;	
	for(int i=0;i<m;i++)
	{
		string aux;
		cin>>aux;
		V.push_back(aux);	 
	}
	cin>>x>>y;
	Ans.push_back(make_pair(V[x][y],dfs(x,y)));
	tierra=V[x][y];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(V[i][j]==tierra && !visitados[i][j])
			{
				Ans.push_back(make_pair(V[i][j],dfs(i,j)));
			}
	int mayor=0;
	for(int i=1;i<Ans.size();i++)
		if(Ans[i].second>mayor)
			mayor=Ans[i].second;
	cout<<mayor<<endl;
	}
	return 0;
}
