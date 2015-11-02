#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef long long ll;
int n, a[MAX], l[MAX], r[MAX];
int main()
{
	while(scanf("%d", &n) == 1)
	{
		if(n<=0) break;
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		l[0]=-1;
		stack < int >  q;
		q.push(0);
		for(int i=1;i<n;i++)
		{
			while(!q.empty() && a[q.top()]>=a[i])
			{
				q.pop();
			}
			if(q.empty()) l[i]=-1;
			else l[i]=q.top();
			q.push(i);
		}
		stack < int  > qp;
		swap(qp, q);
		r[n-1]=n;
		q.push(n-1);
		for(int i=n-2;i>=0;i--)
		{
			while(!q.empty() && a[q.top()]>=a[i])
			{
				q.pop();
			}
			if(q.empty()) r[i]=n;
			else r[i]=q.top();
			q.push(i);
		}
		ll ans=0ll;
		for(int i=0;i<n;i++)
			ans=max(ans, ll(r[i] - l[i]-1)*ll(a[i]));
		printf("%lld\n", ans);
	}	
}

