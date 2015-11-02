#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd (ll x, ll y)
{
	if(y==0) return x;
	return gcd(y, x%y);
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		ll a, b;
		cin>>a>>b;
		while(a%2ll==0ll) a/=2ll;
		while(b%2ll==0ll) b/=2ll;
		if(gcd(a, b) == 1) 
			printf("Y\n");
		else 
			printf("N\n");	
	}
}

