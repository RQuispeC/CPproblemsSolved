#include<bits/stdc++.h>
using namespace std;
long long f(long long x)
{
	return x+ (x*(x+1ll))/2ll;
}
long long sol(double x, long long n)
{
	long long ans=(long long) x;
	if(f(ans-1)>=n)
	{
		while(f(ans-1)>=n)
			ans--;	
	}
	else
	{
		while(f(ans+1)<n)
			ans++;
	}
	return ans;
}
int main()
{
	long long n;
	int c=1;
	while(cin>>n)
	{
		if(n==0) break;
		double tem= 2.*n;
		//cout<<n<<" : "<<sqrt(tem) -1.<<endl;
		tem=ceil(sqrt(tem) -1.);
		long long ans=sol(tem, n);
		cout<<"Case "<<c++<<": "<<ans+3ll<<endl;
	}
}

