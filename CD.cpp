#include<bits/stdc++.h>
#define	INF 1<<30
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
int a[20], n, sum;
int main()
{
	while(scanf("%d %d", &sum, &n)==2 )
	{
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		int ans, minDif=sum+1;
		for(int i=1;i< 1<<n ; i++)
		{
			int suma=0;
			for(int mask=0;mask<n;mask++)
				if(1<<mask & i)
					suma+=a[mask];
			if(sum-suma>=0 && sum-suma<=minDif)
			{
				minDif=sum-suma;
				ans=i;
			}
		}
		for(int i=0;i<n;i++)
			if(ans & 1<<i)
				printf("%d ", a[i]);
		printf("sum:%d\n", sum-minDif);
	}
}

