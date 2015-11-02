#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;
int n,m;
//vector < string > a;
vector < int > ena;
vector < int > dulc;
int main()
{
	bool dis [1010];
	memset( dis , false, sizeof ( dis));
	cin>>n>>m;
	//a.clear();
	ena.clear();
	dulc.clear();
	for(int i=0;i<n;i++)
	{
		int e,d;
		string aux;
		cin>>aux;
		for(int j=0;j<aux.size();j++)
		{
			if(aux[j]=='S') d=j;
			if(aux[j]=='G') e=j;
		}
		ena.push_back(e);
		dulc.push_back(d);	
	}
	bool flag=true;
	int ans=0;
	for(int i=0;i<ena.size() ;i++)
	{
		if(ena[i]>dulc[i]) flag=false;
		if(dulc[i]-ena[i]>=0) dis[dulc[i]-ena[i]]=true;	
		if(dulc[i]-ena[i]>0) ans++; 
	}
	if(!flag)
		cout<<-1<<endl;
	else
	{
		int aux=0;
		for(int i=1;i<1010;i++)
		{
			if(dis[i]) aux++;
		}		
		ans=min(ans, aux);
		cout<<ans<<endl;	
	}		

}

