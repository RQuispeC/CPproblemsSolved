#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int n, c, t;
int a[200005];
int main()
{
	vector < int > ter;
	ter.clear();
	cin>>n>>t>>c;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		if(a[i]>t)
			ter.push_back(i);	
	}
	if(ter.size()==0)
		cout<<n-c+1<<endl;
	else
	{	
		int ans=n-c+1;
		int k=0;
		for(int i=0;i<=n-c && k<ter.size();)
		{
			if(ter[k]>= i && ter[k]<=i+c-1)
			{
				ans--;
				i++;
			}
			else if(ter[k]<i)
				k++;
			else i++;	
		}
		cout<<ans<<endl;
	}
}
