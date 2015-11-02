#include<iostream>
#include<cstring>
#include<vector>
#define MAX 102
using namespace std;
vector <string>a;
int filas ,columnas;
int p[]={0,1,-1,0,1,1,-1,-1};
int q[]={1,0,0,-1,1,-1,1,-1};
bool valid(int i , int j)
{
	return (i>=0 && j>=0 && i<filas && j<columnas);
}
	int f(int i, int j)
{
	int cont=0;
	for(int k=0;k<8;k++)
	{
		int ni=i+p[k];
		int nj=j+q[k];
		if(valid(ni,nj) && a[ni][nj]=='*')
			cont++;
	}
	return cont;
}
int main()
{
	
	
	int t=0;
	bool blank=false;
	while(cin>>filas>>columnas && filas!=0 && columnas !=0)
	{
		a.clear();
		if(blank) cout<<endl;
		blank=true;
		for(int i=0;i<filas;i++)
		{
			string aux;
			cin>>aux;
			a.push_back(aux);
		}
		cout<<"Field #"<<++t<<":"<<endl;
		for(int i=0;i<filas;i++)
		{
			string aux="";
			for(int j=0;j<columnas;j++)
			{
				if(a[i][j]=='.')
					aux.push_back(f(i,j)+'0');
				else 
					aux.push_back('*');
			}		
			cout<<aux<<endl;
		}
		
	}	
	return 0;
}
