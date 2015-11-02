#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
long long power[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768, 65536,131072,262144, 524288,1048576};
vector<long long> multiply(vector<long long> a,vector<long long> b, long long MOD){
	vector<long long> ans(4);
	ans[0]=((a[0]*b[0])%MOD+(a[1]*b[2])%MOD)%MOD;
	ans[1]=((a[0]*b[1])%MOD+(a[1]*b[3])%MOD)%MOD;
	ans[2]=((a[2]*b[0])%MOD+(a[3]*b[2])%MOD)%MOD;
	ans[3]=((a[2]*b[1])%MOD+(a[3]*b[3])%MOD)%MOD;
	return ans;
}
vector<long long> base()
{
	vector<long long> a;
	a.push_back(1);a.push_back(1);
	a.push_back(1);a.push_back(0);
	return a;
}
vector<long long> pow(long long n, long long MOD)
{
	if(n==0)
	{
		vector<long long> a;
		a.push_back(0);a.push_back(0);
		a.push_back(0);a.push_back(0);
		return a;
	}
	else
	{	
		if(n==1)
			return base();
		else{
			if(n%2==0){
				vector<long long> a=pow(n/2,MOD);
				return multiply(a,a,MOD);
			}else
				return multiply(base(),pow(n-1,MOD),MOD);
		}
	}
}
int main()
{
	long long n, m;
	while(cin>>n>>m)
	{
		vector<long long> ans=pow(n,power[m]);
		cout<<ans[2]%power[m]<<endl;
	}	
	return 0;
}

