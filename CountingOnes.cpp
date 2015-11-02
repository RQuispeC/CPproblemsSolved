#include<iostream>
using namespace std;
long long T[56];// # de 1's de 0 a i bits
int m; // 2^m<=x / max(m)

void precal ()
{
	T[0]=0ll;
	T[1]=1ll;
	for(int i=2;i<56;i++)
	{
		T[i]=(2*T[i-1]) + (1ll<<(i-1));	
	}
}	
void limit(long long x)
{
	m=1;
	while(true)
	{
		if((1ll<<(m+1)) <= x)
			m++;
		else
			break;
	}
}
long long f( long long x) // # de 1's de [0,x]
{
	if(x<=1) return x;
	else
	{
		limit(x);
		return T[m]+( x + (1ll) - (1ll<<m) ) + f( x -  (1ll<<m) );
	}	
}
int main()
{
	long long a,b;
	precal();
	while(cin>>a>>b)
	{
		cout<<f(b)-f(a-1ll)<<endl;
	}
}
