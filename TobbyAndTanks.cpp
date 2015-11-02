#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<set>
#include<bitset>
#define MAX 100005
using namespace std;
int n,q;
int aux[MAX];
int f[MAX];
int main()
{
	while(cin>>n>>q)
	{
		for(int i=0;i<n;i++)
			scanf("%d", &aux[i] );
		for(int i=0;i<n;i++)
			if(i==0) f[i]=aux[i];
			else f[i]=f[i-1]+aux[i];
		for(int i=0;i<n;i++)
			f[i]-=(aux[0]-1);
		for(int i=0;i<q;i++)
		{
			int limit;
			scanf("%d", &limit);
			int pos=lower_bound(f, f+n, limit)-f;
			if(pos<n)
				if(f[pos]==limit)
					printf("%d", pos+1);
				else
					printf("%d", pos);
			else
				printf("%d", pos);
			if(i+1<q) printf(" ");		
		}
		printf("\n");
						
	}
}

