#include<bits/stdc++.h>
#define MAX 1e6 + 2
using namespace std;
typedef long long ll;
const int MOD=1000000;
long long x[(int)MAX];
int main()
{
	int li=1e6 +2;
	x[0]=1ll;
	for(int i=1;i<li;i++)
	{
		long long f1=x[ (int) ((double)i-sqrt(i))] % MOD;
		long long f2=x[ (int) (log(i))] % MOD;
		long long f3=x[ (int) ( (double)i* sin (i) *sin(i)) ] %MOD;
		x[i]= (f1+f2+f3) %MOD;
	}
	int n;
	while(cin>>n)
	{
		if(n<0 )  break;
		cout<<x[n]<<endl;
	}
}

