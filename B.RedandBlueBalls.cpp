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
long long fastPow( int i)
{
	long long ans=1;
	while(i>0)
	{
		
	} 
}
int main()
{
	int n;
	string a;
	cin>>n>>a;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='B')
		{
			long long aux=1LL<<i;	
			ans+=aux;
		}	
	}
	cout<<ans<<endl;	
}

