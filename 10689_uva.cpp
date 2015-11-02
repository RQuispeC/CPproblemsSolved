#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#define MOD 10000
using namespace std;
vector<int> mul(vector<int> a,vector<int> b){
	vector<int> c(4);
	c[0]=((a[0]*b[0])%MOD+(a[1]*b[2])%MOD)%MOD;
	c[1]=((a[0]*b[1])%MOD+(a[1]*b[3])%MOD)%MOD;
	c[2]=((a[2]*b[0])%MOD+(a[3]*b[2])%MOD)%MOD;
	c[3]=((a[2]*b[1])%MOD+(a[3]*b[3])%MOD)%MOD;
	return c;
}
vector<int> mb(){
	vector<int> a;
	a.push_back(1);a.push_back(1);
	a.push_back(1);a.push_back(0);
	return a;
}
vector<int> f(int n){
	if(n==1)
		return mb();
	else{
		if(n%2==0){
			vector<int> a=f(n/2);
			return mul(a,a);
		}else
			return mul(mb(),f(n-1));
	}
}
int p10[]={1,10,100,1000,10000};
int main(){
	int t,a,b,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d",&a,&b,&n,&m);
		vector<int> M=f(n);
		printf("%d\n",(M[2]*b+M[3]*a)%p10[m]);
	}
}
