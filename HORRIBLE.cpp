#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n , c;
ll ST[3*MAX],lazy[3*MAX];
void fit(int p, int i, int j)
{
	if(lazy[p])
	{
		ST[p]+=(ll(j-i+1)*(lazy[p]));
		if(i!=j)
		{
			lazy[2*p]+=lazy[p];
			lazy[2*p+1]+=lazy[p];
		}
		lazy[p]=0;
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
			lazy[2*p]+=ll(val),	lazy[2*p+1]+=ll(val);
		return;
	}	
	int m=(i+j)/2;
	update(2*p,i,m,l,r,val);
	update(2*p+1,m+1,j,l,r,val);
	ST[p]=ST[2*p] + ST[2*p+1];
}
ll query(int p, int i, int j, int l, int r)
{
	fit(p,i,j);
	if(r<i || j<l) return 0ll;
	if(l<=i && j<=r) return ST[p];
	int m=(i+j)/2;
	return query(2*p,i,m,l,r) + query(2*p+1,m+1,j,l,r);
	
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
			int op,p,q,val;
			scanf("%d %d %d", &op, &p, &q);
			if(!op)
			{
				scanf("%d", &val);
				update(1,0,n-1,p-1,q-1,val);
			}
			else
				printf("%lld\n", query(1,0,n-1,p-1, q-1 ));
		}
	}
}

