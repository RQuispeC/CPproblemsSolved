#include<iostream>
#include<cmath>
#define MAX 1000000
using namespace std;
long long n;
struct factor
{
	long long base, exp;
	factor()
	{
		base=0;
		exp=0;
	}
	factor(long long b, long long  e )
	{
		base=b;
		exp=e;
	}
};
factor a[MAX];
int main()
{
	while(cin>>n)
	{
		long long nn=n;
		if(n<=0) break;
		int nroFact=0;
		for(long long i=2;i*i<=n;i++)
		{
			int aux=0;
			while(n%i==0)
			{
				aux++;
				n/=i;
			}
			if(aux>0)
			{
				a[nroFact++]=factor(i,aux);
			}
		}
		if(n>1)
			a[nroFact++]=factor(n,1);
		long long ans1=1, ans2=1;
		for(int i=0;i<nroFact;i++)
		{
			//cout<<a[i].base<<"  :    "<<a[i].exp<<endl;
			long long temp=a[i].exp/2;
			if(temp>=1)
			{
				long long aux=( long long ) pow(a[i].base, temp);
				ans1*=aux;
			}
			ans2*=(long long ) pow(a[i].base, a[i].exp % 2);
		}
		cout<<ans1<<" "<<ans2<<endl;			
	}
}
