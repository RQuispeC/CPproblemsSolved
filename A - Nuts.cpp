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
int k ,a, b, v;
int main()
{
	cin>>k>>a>>b>>v;
	int ans=0;
	while(a>0)
	{
		int max;
		if(b>k-1)
		{
			max=k*v;
			b-=(k-1);			
		} 
		else
		{
			max=(b+1)*v;
			b=0;
		}
		if(a>=max)
		{
			ans++;
			a-=max;
		}
		else 
		{
			a=0;
			ans++;		
			break;
		}		
	}
	cout<<ans<<endl;
	
	

}

