#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long ans[35];
	ans[0]=0ll;
	for(int i=1;i<35;i++)
		ans[i]=1ll+ans[i-1]*2ll;
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		cout<<ans[n]<<endl;
	}	
}

