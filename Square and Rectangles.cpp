#include <iostream>
#include <string.h>
#include<algorithm>
#include<cstring>

using namespace std;
int c[5][5];
int areas[5];
int main()
{
	memset(c,0,sizeof(c));
	memset(areas,0,sizeof(areas));
	int n,minX,minY,maxX=0,maxY=0;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<4;j++)
			cin>>c[i][j];
	minY=c[0][1];
	minX=c[0][0];
	for(int i=0;i<n;i++)
	{
		if(c[0][i]>maxX)
			maxX=c[0][i];
		if(c[2][i]>maxX)
			maxX=c[2][i];
		if(c[1][i]>maxY)
			maxY=c[1][i];
		if(c[3][i]>maxY)
			maxY=c[3][i];
			
		if(c[0][i]<minX)
			minX=c[0][i];
		if(c[2][i]<minX)
			minX=c[2][i];
		if(c[1][i]<minY)
			minY=c[1][i];
		if(c[3][i]<minY)
			minY=c[3][i];
	}
	int areaTo=(maxX-minX)*(maxY-minY);
	int area=0;
	for(int i=0;i<n;i++)
	{		
		areas[i]+=(c[i][2]-c[i][0])*(c[i][3]-c[i][1]);
		area+=(c[i][2]-c[i][0])*(c[i][3]-c[i][1]);		
	}
	
	if(area==areaTo && (maxX-minX==maxY-minY))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
	return 0;	
}
