#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
int a[100005];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	int ans=0;
	int dis=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
		{
			dis+=a[i];
		}
		else
		{
			if(dis<=0)
				ans++;
			else
				dis--;
		}
	}
	cout<<ans<<endl;	
}
