#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef long long ll;
int n , c;
ll ST[5*MAX],lazy[5*MAX], ans[MAX];
void fit(int p, int i, int j)
{
	if(lazy[p])
	{
		ST[p]+=ll(j-i+1)*ll(lazy[p]);
		if(i!=j)
		{
			lazy[2*p]+=lazy[p];
			lazy[2*p+1]+=lazy[p];
		}
		lazy[p]=0ll;
	}
}
void update(int p, int i, int j, int l, int r, int val)
{
	fit(p,i,j);
	if(r<i || j<l) return;
	if(l<=i && j<=r) 
	{
		ST[p]+=(ll(j-i+1)*ll(val));
		if(i!=j)
			lazy[2*p]+=ll(val), lazy[2*p+1]+=ll(val);
		return;
	}	
	int m=(i+j)/2;
	update(2*p,i,m,l,r,val);
	update(2*p+1,m+1,j,l,r,val);
	ST[p]=ST[2*p] + ST[2*p+1];
}
void getQuery(int p, int i, int j)
{
	fit(p, i, j);
	if(i==j)
	{
		ans[i]=ST[p];
		return;
	}
	int m=(i+j)>>1;
	getQuery(2*p,i, m);
	getQuery(2*p+1,m+1, j);
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		memset(ST,0ll,sizeof ST);
		memset(lazy, 0ll,sizeof lazy);
		scanf("%d %d", &n, &c);
		while(c--)
		{
			int p,q,val;
			scanf("%d %d %d", &p, &q, &val);
			if(p>q) swap(p,q);
			update(1,0,n-1,p,q,val);
		}
		getQuery(1, 0, n-1);
		scanf("%d", &c);
		while(c--)
		{
			int u;
			scanf("%d", &u);
			printf("%lld\n", ans[u]);
		}
	}
}

