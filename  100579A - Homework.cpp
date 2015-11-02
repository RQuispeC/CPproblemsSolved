#include<bits/stdc++.h>
#define MAX 10000005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int p[MAX];
void sol()
{
	memset(p, -1, sizeof p);
	for(int i=2;i<MAX;i++)
		if(p[i]==-1)
		for(int j=i;j<MAX;j+=i)
			if(p[j]==-1) p[j]=1;
			else p[j]++;
	
}
int main()
{
	sol();
	int test;
	scanf("%d", &test);
	for(int te=1;te<=test;te++)
	{
		int  a, b, k;
		scanf("%d %d %d", &a, &b, &k);
		if(k>7)
		{
			printf("Case #%d: 0\n", te);
			continue;
		}
		int ans=0;
		for(int i=a;i<=b;i++)
		{
			if(p[i]==-1) p[i]=1;
			if(p[i]==k)  ans++;
		}
		printf("Case #%d: %d\n", te, ans);	
	}
}

