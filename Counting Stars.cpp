#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 100
using namespace std;
int m,n;
vector <string> V;
bool visitados[MAX][MAX];
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
bool esValido(int a, int b)
{
	return a>=0 && b>=0 && a<m && b<n;
}
int dfs(int a, int b){
	visitados[a][b] = 1;
	int k  = 1;
	for(int i = 0; i < 8; i++){
		int na = a + dy[i];
		int nb = b + dx[i];
		
		if(esValido(na,nb) &&  V[a][b]==V[na][nb] && !visitados[na][nb])//verifica si es valido, si el que le sigue el igual y si ya todavia no ha sido visitado
		{
			k += dfs(na,nb);
		}
	}
	
	return k;
}
int main()
{
	while(cin>>m && cin>>n && m!=0 && n!=0)
	{
		V.clear();
		memset(visitados,0,sizeof(visitados));
		for(int i=0;i<m;i++)
		{
			string aux;
			cin>>aux;
			V.push_back(aux);	
		}
		int total=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(V[i][j]=='*' && !visitados[i][j])
					if(dfs(i,j)==1)
						total++;
					
		cout<<total<<endl;		
		
	}
	return 0;
}
