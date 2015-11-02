#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int a[100005];
int main()
{
	a[1]=0;
	a[2]=1;
	for(int i=3;i<100005;i++)
		a[i]=(a[i-1] +a[i-2]) %MOD;
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}
}

