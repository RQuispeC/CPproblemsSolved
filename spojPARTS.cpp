#include<iostream>
#define MOD 1000000007
using namespace std;
long long pow(long long  a, long long b)
{
    long long ans=1;
    while(b>0)
    {
        if(b&1) ans=(ans*a)%MOD;
        b>>=1;
        a=(a*a)%MOD;
        
    }
    return ans;
}
int main()
{
    long long n;
    int tested;
    cin>>tested;
    while(tested--)
    {
          cin>>n;
          if(n>1)
            cout<<pow(2,n-2)*(n+1)<<endl;
          else
            cout<<1<<endl;
    }
}

