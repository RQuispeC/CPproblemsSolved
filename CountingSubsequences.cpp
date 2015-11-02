#include<bits/stdc++.h>
#define MAX (int) 1e6 +5
using namespace std;
typedef long long ll;
int  n, ans;
ll ac[MAX];
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		ans=0;
		scanf("%d", &n);
		cin>>ac[0];
		for(int i=1;i<n;i++)
		{
			int x;
			scanf("%d", &x);
			ac[i]=ll(x)+ac[i-1];
		}
		ll ans=0ll;
		for(int i=0;i<n;i++)
		{
			ll x;
			if(i==0) x=47ll;
			else x=ac[i-1]+47ll;
			int posB=lower_bound(ac, ac+n, x ) - ac;
			int posE=upper_bound(ac, ac+n, x ) - ac;
			if(ac[posB]==x)
			{
				posE--;
				cout<<i<<": "<<posB<<" * "<<posE<<" ";
				if(ac[posE]==x)
					ans+=ll(posE - posB + 1);
				else
					ans++;
				cout<<ans<<endl;	
			}
		}
		cout<<ans<<endl;
	}
}

