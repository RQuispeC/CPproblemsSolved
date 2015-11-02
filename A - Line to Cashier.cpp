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
using namespace std;
int a[105];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans=1000000000;
	for(int i=0;i<n;i++)
	{
		int con=0;
		for(int j=0;j<a[i];j++)
		{
			int aux;
			cin>>aux;
			con+=(aux*5);
		}
		con+=(15*a[i]);
		ans=min(ans, con);		
	}
	cout<<ans<<endl;
}

