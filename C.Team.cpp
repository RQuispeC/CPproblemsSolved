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
using namespace std;
int n,m;
string ans;
int main()
{
	cin>>n>>m;
	if( (m > 2*n+2 ) || ( n > m+1 ) )
		cout<<-1<<endl;
	else
	{
		ans=="";
		if(n==m)
		{
			for(int i=0;i<n;i++)
				ans+="10";	
		}
		else if(n==m+1)
		{
			for(int i=0;i<m;i++)
				ans+="01";
			ans+="0";	
		}
		else
		{
			if(2*n>m)
			{
				int x=m-n;
				for(int i=0;i<x;i++)
					ans+="110";
				n-=x;
				for(int i=0;i<n;i++)
					ans+="10";
			}
			else
			{
				for(int i=0;i<n;i++)
					ans+="110";
				m-=(2*n);
				for(int i=0;i<m;i++)
					ans+="1";	
			}	
		}
		cout<<ans<<endl;
	}			
}

