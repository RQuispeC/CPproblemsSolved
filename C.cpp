#include<bits/stdc++.h>
#define	INF 1e9
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 105
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
typedef pair< ll, ll > pll;
ll t, w, b;
int main()
{
    cin>>t>>w>>b;
    double GCD = (double)(__gcd(w, b));
    double y = (1.0*w*b)/GCD;
    ll ans = (ll)((double)(t)/y);
    ll res = (ll)( (double)(t) - 1.0*y*ans);
    ans += ans*(min(b, w) - 1ll) + min(min(b, w) - 1ll, res);
    ll fact = __gcd(ans, t);
    cout<< ans/fact <<"/"<< t/fact<<endl;
}

