#include<bits/stdc++.h>
#define MAX  10005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n, p[MAX], memo[MAX], f[MAX];
struct work
{
	int left, right, cost;
	work(){}
	work(int l , int r, int c)
	{
		left=l, right=r, cost=c;
	}
	bool operator < ( work x) const
	{
		return right<x.right;
	}
};
work a[MAX];
void getP()
{
	for(int i=1;i<=n;i++)
	{
		int pos=lower_bound(f, f+n+1,a[i].left) - f;
		p[i]=max(0,pos-1);
	}
}
int dp(int pos)
{
	if(pos==0) return 0;
	if(memo[pos] != -1 ) return memo[pos];
	int ans=a[pos].cost + dp(p[pos]);
	ans=max(ans, dp(pos-1));
	return memo[pos]=ans;
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		memset(memo, -1, sizeof memo);
		f[0]=0;
		a[0]=work(0,0,0);
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
		{
			int beg, len, cost;
			scanf("%d %d %d", &beg, &len, &cost);
			a[i]=work(beg, beg + len ,  cost);
			f[i]=beg + len;
		}
		sort(a, a+n+1);
		sort(f, f+n+1);
		getP();
		printf("%d\n", dp(n));
	}
}

