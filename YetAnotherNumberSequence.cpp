#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector> 
#define MOD 10000
using namespace std;
int digits[]={1,10,100,1000,10000}; 
vector<int> f;

vector<int> multiply(vector<int> a,vector<int> b){
	vector<int> ans(4);
	ans[0]=((a[0]*b[0])%MOD+(a[1]*b[2])%MOD)%MOD;
	ans[1]=((a[0]*b[1])%MOD+(a[1]*b[3])%MOD)%MOD;
	ans[2]=((a[2]*b[0])%MOD+(a[3]*b[2])%MOD)%MOD;
	ans[3]=((a[2]*b[1])%MOD+(a[3]*b[3])%MOD)%MOD;
	return ans;
}
vector<int> base()
{
	vector<int> a;
	a.push_back(1);a.push_back(1);
	a.push_back(1);a.push_back(0);
	return a;
}
vector<int> pow(int n)
{
	if(n==1)
		return base();
	else{
		if(n%2==0){
			vector<int> a=pow(n/2);
			return multiply(a,a);
		}else
			return multiply(base(),pow(n-1));
	}
}

int main()
{
	int tested;
	scanf("%d",&tested);
	while(tested--)
	{
		int a,b,n,m; 
		scanf("%d %d %d %d",&a,&b,&n,&m);
		vector<int > ans=pow(n);
		cout<<(ans[2]*b+ans[3]*a)%digits[m]<<endl; 
	}
	return 0;
}

