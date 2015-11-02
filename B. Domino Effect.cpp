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
string a;
int n;
int main()
{
	vector < int > mov;
	mov.clear();
	cin>>n>>a;
	int cont=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!='.' )
		{
			mov.push_back(i);
		}
		else cont++;
	}
	int ans=0;
	if(mov.size()!=0)
	{
		for(int i=0;i+1<mov.size();i++)
		{
			if(a[mov[i]]=='R' && a[mov[i+1]]=='L')
			{
				ans+=(mov[i+1]-mov[i]+1)%2;
			}
			else if(a[mov[i]]=='L' && a[mov[i+1]]=='R')
			{
				ans+=(mov[i+1]-mov[i]-1);
			}		
		}
		if(a[mov[0]]=='R')
			ans+=mov[0];
		if(a[mov[mov.size()-1]]=='L')
			ans+=(n-1-mov[mov.size()-1]);
			cout<<ans<<endl;
	}
	else cout<<n<<endl;	
			
}

