#include<bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long x, unsigned long long y)
{
	if(y==0) return x;
	if(x==0) return y;
	return gcd(y, x % y);
}
int main()
{
	int a[10];
	int test;
	cin>>test;
	for(int te=1;te<=test;te++)
	{
		int n;
		cin>>n;
		unsigned long long prod=1ll;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			prod*=a[i];
		}
		unsigned long long num=prod*n;
		unsigned long long den=0ll;
		for(int i=0;i<n;i++)
		{
			den+=(prod/a[i]);
		}
		unsigned long long GCD=gcd(num, den);
		cout<<"Case "<<te<<": "<<num/GCD<<"/"<<den/GCD<<endl;
	}
}


