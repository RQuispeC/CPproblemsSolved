#include<bits/stdc++.h>
#define MOD (long long ) 1000000007
using namespace std;
typedef long long ll;
typedef vector < int > vi;
vi f;
ll fun(int n, ll val) //sumatoria de los lim primeros mult. de val
{
	ll lim=ll(n)/val;
	if(ll(n)%val == 0 ) lim--;
	lim=max(lim, 0ll);
	ll ans = ll(((lim*(lim+1ll))/2ll))*ll(val);
	return ans;
}
void getFactors(int n)//factorización
{
	set < int > s;
	s.clear();
	for(int i=2;i*i<=n;i==2?i++:i+=2)
	{
		if(n%i==0)
			while(n%i==0)
			{
				s.insert(i);
				n/=i;
			}
	}
	if(n>1) s.insert(n);
	vi tmp (s.begin(), s.end());
	swap(tmp, f);
}
ll sol(int n)
{
	ll ans=0ll;
	for(int mask=1;mask<(1<<f.size());mask++)
	{
		int numEl=__builtin_popcount(mask);
		ll num=1ll;
		for(int j=0;j<f.size();j++)
			if(mask & (1<<j))
				num*=ll(f[j]);
		if(numEl & 1) //positive sign
			ans+=fun(n, num);		
		else
			ans-=fun(n, num);	
	}
	return ans%MOD;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n<=0) break;
		getFactors(n);
		cout<<sol(n)<<endl;	
	}
}

