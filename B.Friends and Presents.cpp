//problem: http://codeforces.com/problemset/problem/483/B
#include<bits/stdc++.h>
#define	INF 1ll<<60
#define MAX 200005
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define EPS 1e-9
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
ll cnt1, cnt2, x, y;
ll f(ll n)
{
    if(n - n/x < cnt1) return -INF;
    if(n - n/y < cnt2) return -INF;
    return n - n/(x*y);
}
int main()
{
    cin>>cnt1>>cnt2>>x>>y;
    ll hi = 1ll<<60, lo = 0ll;
    while(hi-lo>1ll)
    {
        ll  m = (hi+lo)/2ll;
        if(f(m)>=cnt1+cnt2)
            hi=m;
        else
            lo=m;
    }
    
    cout<<hi<<endl;
}

