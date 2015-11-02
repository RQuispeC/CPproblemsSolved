#include<bits/stdc++.h>
#define MAX (int)1e7 +5
using namespace std;
typedef long long ll;
int BIT[MAX];
int f(int x)
{
	return x & -x;
}
void update(int ind, int val)
{
	while(ind<=MAX)
	{
		BIT[ind]+=val;
		ind+=f(ind);
	}
}
int query(int ind)
{
	int ans=0;
	while(ind>0)
	{
		ans+=BIT[ind];
		ind-=f(ind);
	}
	return ans;
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		memset(BIT, 0, sizeof BIT);
		int n;
		scanf("%d", &n);
		ll ans=0ll;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d", &x);
			ans+=ll(i-query(x));
			update(x, 1);
		}
		cout<<ans<<endl;
	}
}

