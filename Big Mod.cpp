#include<stdio.h>
#include<iostream>
using namespace std;
long long PowMod(long long a, long long b, long long MOD)
{
	long long ans=1;
	while(b>0)
	{
		if(b&1==1)
			ans=(ans*a)%MOD;
		b>>=1;
		a=(a*a)%MOD;
	}
	return ans; 
}
int main()
{
	int a, b, mod;
	while(cin>>a>>b>>mod)
	{
		cout<<PowMod(a,b,mod)<<endl;
	}
	return 0;
}

