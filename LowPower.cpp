#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int a [ 1000005];
	int n, k;
	while(cin>>n>>k)
	{
		for(int i=0;i<2*n*k;i++)
			scanf("%d", & a[i]);
		sort(a, a+n);
		int ans=a[1]-a[0];
		int aux=0;
		for(int i=1;i<n;i++)
		{
			int li=2;
			bool find=false;
			for(int j=aux+2;j<=li*k;j++)
			{
				if(ans<=a[j+1]-a[j])
				{
					aux=j;	
					find=true;
					break;
				}
			}
			if(!find)
				aux+=2;
			ans=max(ans, a[aux+1]-a[aux]);	
			li+=2;
		}
		printf("%d\n", ans);
	}
}

