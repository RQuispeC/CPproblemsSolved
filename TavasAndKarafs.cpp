// problem: http://codeforces.com/problemset/problem/535/C
// solution by rodo
#include<bits/stdc++.h>
#define INF 1<<30
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
const ll MAX  = 1ll<<30;
ll A, B, q;
ll l, t, m;
ll costAt(ll r)
{
    ll costR, costL;
    if(r%2ll==0) costR = (r/2ll)*(r-1ll);
    else costR = ((r-1ll)/2ll)*(r);
    if(l%2ll==0) costL = ((l-2ll)/2ll)*(l-1ll);
    else costL = ((l-1ll)/2ll)*(l-2ll);
    return (r - l +1ll)*A + (B)*(costR  - costL);
        
}
ll heightAt(ll r)
{
    return A+B*(r-1ll);
}
ll sol()
{
    ll left=l-1 , right = MAX;
    while(right-left>1ll)
    {
        ll mid=(right+left)>>1;
        if(heightAt(mid)>t)
            right=mid;
        else    
            left=mid;
    }
    if(left==l-1) return -1;
    right=left+1, left=l;
    ll lim=m*t;
    while(right-left>1ll)
    {
        ll mid=(right+left)>>1;
        if(costAt(mid)<=lim)
            left=mid;
        else    
            right=mid;
    }
    return left;
}
int main()
{
    cin>>A>>B>>q;
    while(q--)
    {
        cin>>l>>t>>m;
        cout<<sol()<<endl;
    }
}
