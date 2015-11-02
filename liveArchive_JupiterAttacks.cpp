#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 300000
using namespace std;
long long ST[MAX];             //arreglo del segmen tree
long long A[MAX];              //arreglo original         
long long b,mod,l,n;
pair< long long , long long > eGCD(long long x, long long y)
{
	if(y==0)
	{
		return make_pair(1ll,0ll);	
	}
	else
	{
		pair < int , int > ans=eGCD(y,x%y);
		return make_pair(ans.second, ans.first-ans.second*(x/y));
	}
}
long long inverMod(long long x, long long m)
{
	pair < long long, long long > EGCD= eGCD(x , m);
	return ((EGCD.first % m) + m ) % m;
}
long long pow(long long a,long long  b )
{
  long long ans=1ll;
  while(b>0)
  {
    if(b&1ll) ans=(ans*a)%mod;
    b>>=1;
    a=(a*a)%mod;
  }
  return ans;
}
long long operation (long long x, long long y)
{
  return (x+y)%mod;
}
void build(int n,int i,int j){
	if(i==j) 
		ST[n]=(( A[i] % mod ) * pow(b, l-1-i) ) % mod;
	else
	{
		int m=(i+j)/2;
		build(n*2,i,m);
		build(n*2+1,m+1,j);
		ST[n]=operation(ST[n*2],ST[n*2+1]);
	}
}
void update(int n, int i, int j, int x, int  v){
	if(i==j && i==x)
	{
	  ST[n]=(( v % mod ) * pow(b, l-1-i) ) % mod;
	  return;     
	} 
	if(x<i || j<x)
	  return; 
	int m=(i+j)/2;
	update(n*2,i,m,x,v);
	update(n*2+1,m+1,j,x,v);
	ST[n]=operation(ST[n*2],ST[n*2+1]);
}
long long query(int n,int i,int j,int iq,int jq )
{
	if(iq<=i && j<=jq)return ( ST[n]*inverMod( pow(b,l-1-jq )+mod , mod ) %mod ) ; 
	if(j<iq || jq<i) return 0; 
	int m=(i+j)/2;
	return operation(query(n*2,i,m,iq,jq),query(n*2+1,m+1,j,iq,jq));
}

int main()
{
    while( cin>>b>>mod>>l>>n) 
    {
        if(b==0 && mod==0 && l==0 && n==0 ) break;
        memset (A,0,l+5);
        build(1,0,l-1);
        for(int i=0;i<n;i++)
        {
            char op;
            cin>>op;
            if(op=='E')
            {
                long long i,v;
                cin>>i>>v;
                update(1,0,l-1,i-1,v);
            }
            else
            {
                long long i,j;
                cin>>i>>j;
                long long a=query(1,0,l-1,i-1,j-1);
                cout<<a<<endl;
            } 
           
        }
         cout<<"-"<<endl; 
    } 
}

