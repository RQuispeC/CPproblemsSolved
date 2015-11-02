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
int main()
{
	int n, k;
	cin>>n>>k;
	int a[2000];
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	sort(a, a+n);
	int ans=0;
	for(int i=2;i<n;i=i+3)
	{
		//cout<<"i:"<<i<<endl;
		//cout<<a[i]+k<<endl;
		if(a[i]+k<=5)
			ans++;
	}
	cout<<ans<<endl;
}
