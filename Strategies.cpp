#include<bits/stdc++.h>
#define MAX 2000
using namespace std;
int a[30],b[30], c[30], n;
int timeA[MAX], timeB[MAX], timeC[MAX], cont[3];
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int limit;
		scanf("%d %d", &limit, &n);
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			b[i] = c[i] = a[i];
		}
		sort(b, b+n);
		sort(c+n, c);
		for(int i=0;i<n;i++)
			cout<<b[i]<<" : "<<c[i]<<endl;
		memset(timeA, 0, sizeof A);
		memset(timeB, 0, sizeof B);
		memset(timeC, 0, sizeof C);
		memset(cont, 0, sizeof cont);

		int timer = 0;
		int i=0;
		while(1)
		{
			if(i==n || timer>limit) break;
				
		}
	}
}
