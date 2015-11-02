#include <iostream>
#include <string.h>
#include<algorithm>
#include<cstring>
#define MAX 10
using namespace std;
int cuadrado[MAX][MAX];
int total(int x,int y, int limiteX,int limiteY)
{
	int tot=0;
	for(int i=x;i<limiteX;i++)
	{
		tot+=cuadrado[y][i];
		tot+=cuadrado[limiteY-1][i];
		
	}
	for(int i=y+1;i<limiteY-1;i++)
	{
		tot+=cuadrado[i][x];
		tot+=cuadrado[i][limiteX-1];				
	}
	return tot;		
}

int main()
{
	int n;
    cin>>n;
	int cas=0;
	while(n!=0)
	{
		int sum=0;
		memset(cuadrado,0,sizeof(cuadrado));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>cuadrado[i][j];
				sum+=cuadrado[i][j];
			}
		}
		
		cas++;
		cout<<"Case "<<cas<<": ";
		if(n%2==0)
		{
			int X=0,Y=0,LX=n,LY=n;
			int concentricos=n/2;
			int aux=0;
			for(int i=0;i<concentricos-1;i++)
			{ 
				int r=total(X,Y,LX,LY);
				cout<<r<<" ";
				X++;
				Y++;
				LX--;
				LY--;
				aux+=r;
			}
			cout<<sum-aux<<endl;
		}
		else
		{
			int X=0,Y=0,LX=n,LY=n;
			int concentricos=n/2+1;
			int aux=0;
			for(int i=0;i<concentricos-1;i++)
			{ 
				int r=total(X,Y,LX,LY);
				cout<<r<<" ";
				X++;
				Y++;
				LX--;
				LY--;
				aux+=r;
				
			}
			cout<<sum-aux<<endl;
		}
			
		cin>>n;		
	}			
	return 0;
}

