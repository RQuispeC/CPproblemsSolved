#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<string>
#include<map>
#define MAX 1010
using namespace std;
int a[MAX];
int n,x;
int main()
{
	cin>>n>>x;
	int tot=0;
	for(int i=0;i<n;i++)
	{
		int aux;
		cin>>aux;
		tot+=aux;
	}
	if(tot==0)
		cout<<0<<endl;
	else if(tot<0)
	{
		tot*=-1;
		int ans=tot/x;
		tot%=x;
		if(tot>0) ans++;
		cout<<ans<<endl;
	}
	else
	{
		int ans=tot/x;
		tot%=x;
		if(tot>0) ans++;
		cout<<ans<<endl;
	}	
}

