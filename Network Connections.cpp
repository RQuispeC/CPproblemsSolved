#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#define N 1000000
using namespace std;
int U[N];
int find(int a)
{
	if(U[a]==a)
		return a;
	else  //return find(U[a]);
		return U[a]=find(U[a]);
}
int main()
{
	int cases;
	cin>>cases;
	long long n;
	bool R=false;
	while(cases--)
	{
		int correctos=0;
		int incorrectos=0;
		int x,y;
		char opc;
		cin>>n;	
		for(int i=0;i<N;i++)
			U[i]=i;	
		opc=cin.get();
		opc=cin.get();
		while(true)
		{
			if(opc=='\n' || opc==EOF) break;
			cin>>x>>y;
			int findX=find(x);
			int findY=find(y);
			if(opc=='c')
				U[findX]=findY;
			else
			{
				if(findX==findY)
					correctos++;
				else
					incorrectos++;	
			}
			opc=cin.get();
			if(opc==EOF) break;
			opc=cin.get();
		}
		if(R)
			cout<<endl;
		R=true;
		cout<<correctos<<","<<incorrectos<<endl;
		
	}
	return 0;
}
