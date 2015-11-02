#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
int  fib[45], n , fi, s, w[MAX], f[MAX];
void generate()
{
	fib[0]=0, fib[1]=1;
	for(int i=2;i<45;i++)
	{
		fib[i]=fib[i-1 ]+ fib[i-2];
	}
}	
int fun(int x)
{
	if(binary_search(fib, fib+45, x))
		return 0;
	int pos=upper_bound(fib, fib+45, x) - fib;
	return fib[pos]-x;
}
int main()
{
	generate();
	while(scanf("%d %d %d", &n, &fi, &s) == 3)
	{
		if(n==0 && fi==0 && s==0) break;
		for(int i=0;i<n;i++)
		{
			scanf("%d", &w[i]);
			f[i]=fun(w[i]);
		}
		sort(f, f+n);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(f[i]<=fi)
			{
				ans++;
				fi-=f[i];
			}
			else
				break;
		}
		printf("%d\n", ans);
	}
}

