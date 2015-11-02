#include <iostream>
#define MOD 100
using namespace std;
long long sum,n, m;
long long  ModPow(long long a, int b)
{
	long long res=1LL;
	while(b>0)
	{
		if(b&1)// si b es impar
			res=(res*a)%MOD;
		b=b>>1;//divides b entre 2  
		a=(a*a)%MOD;
	}
	return res;	
}
int suma(int x)
{
	return x%MOD;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		sum=1;	
		for(int i=2;i<=n;i++)
		{
			sum+=ModPow(i,m);
		}
		cout<<suma(sum)<<endl;
	}
	return 0;
}
