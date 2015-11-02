#include<iostream>
#include<cmath>
#include<cstring>
#define MAX 110
int n;
bool a [MAX][MAX];
bool x [MAX];
bool y [MAX];
using namespace std;
int main()
{
	memset(a, false, sizeof a);
	memset(x, false, sizeof x);
	memset(y, false, sizeof y);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y]=true;
	}
	for(int i=0;i<MAX;i++)
	{
		bool ans=false;
		for(int j=0;j<MAX && !ans;j++)
			ans=ans || a[i][j];
		x[i]=ans;		
	}
	for(int i=0;i<MAX;i++)
	{
		bool ans=false;
		for(int j=0;j<MAX && !ans;j++)
			ans=ans || a[j][i];
		y[i]=ans;		
	}
	int X=0, Y=0;
	for(int i=0;i<MAX;i++)
	{
		if(x[i]) X++;
		if(y[i]) Y++;
	} 
	cout<<min(X,Y)<<endl;
}

