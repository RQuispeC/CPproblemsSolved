#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
int tabla[MAX][MAX];
int a[MAX][MAX];
int rows,columns;
int dp(int i, int j)
{
	if(i<0 || i>=rows || j<0 || j>=columns)
		return 0;
	if(tabla[i][j]!= -1) return tabla[i][j];
	int ans=a[i][j];
	ans+=dp(i-1,j);
	ans+=dp(i,j-1);
	ans-=dp(i-1,j-1);
	return tabla[i][j]=ans;
}
int query(int i1, int i2, int j1 , int j2)
{
	return tabla[i2][j2]-tabla[i2][j1]-tabla[i1][j2]+tabla[i1][j1];
}
int main()
{
	memset(tabla , -1 , sizeof tabla);
	int r,c;
	cin>>r>>c;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin>>a[i][j];
	cout<<"elmentos"<<endl;			
	cout<<"%%%%%%%%%%%%%%%s"<<endl;	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<a[i][j]<<"   ";
		cout<<endl;
	}
	cout<<"%%%%%%%%%%%%%%%s"<<endl;	
	tabla[0][0]=a[0][0];		
	int i1,i2,j1,j2;
	cin>>i1>>j1>>i2>>j2;
	dp(r-1,c-1);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<tabla[i][j]<<"   ";
		cout<<endl;
	}
	cout<<query(i1-1,i2-1,j1-1,j2-1)<<endl;
}	
