#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long  ll;
ll mod;
ll f(string x, int b)
{
	ll ans=0ll;
	ll pot=1ll;
	for(int i=x.size()-1;i>=0;i--)
	{
		ans= ( ans+  (pot* ll(x[i]-'0')%mod)) % mod;
		//cout<<" : "<<ans<<endl;
		pot= (pot*ll(b))%mod;
	}
	return ans;
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		string num;
		int b, t;
		cin>>t>>b>>num;
		mod=b-1;
		ll n=f(num , b);
		//cout<<"--> "<<n<<endl;
		cout<<t<<" "<<n%mod<<endl;
	}
}
