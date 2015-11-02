#include<bits/stdc++.h>
#define INF 1ll<<60
#define MAX 1005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n, l, x[MAX], b[MAX], next[MAX];
pii memo[MAX];
const double EPS = 1e-9;
inline pii dp(int pos)
{
    if(pos==n) 
    {
        next[pos] = pos;
        cout<<pos<<" -*> "<<1<<" : "<<b[pos]<<endl;
        return pii(1, b[pos]);
    }
    if(memo[pos]!=pii(-1, -1)) return memo[pos];
    pii ans;
    double best = INF;
    for(int i=pos+1;i<=n;i++)
    {
        pii nextDP = dp(i);
        double tmp = (double)(abs(x[i] - x[pos] - l) + (double) nextDP.first)/(double)(b[pos] + nextDP.second);
        if(tmp<INF)
        {
            best = tmp;
            ans = pii(abs(x[i] - x[pos] - l) + nextDP.first,b[pos] + nextDP.second);
            next[pos] = i;
        }
    }
    //cout<<pos<<" : "<<next[pos]<<endl;
    cout<<pos<<" -> "<<ans.first<<" : "<<ans.second<<endl;
    return memo[pos] = ans;
}
void sol()
{
    for(int i=n-1;i>=0;i--)
        dp(i);
}
int main()
{
    x[0] = b[0]=0;
    scanf("%d %d", &n, &l);
    for(int i=1;i<=n;i++)
        scanf("%d %d", &x[i], &b[i]);
    for(int i=0;i<=n;i++)
            memo[i]=pii(-1, -1);
    sol();
    int pos=next[0];
    while(next[pos] != pos)
    {
        printf("%d ", pos+1);
        pos = next[pos];
    }
    cout<<(double)memo[0].first/(double)(memo[0].second)<<endl;
    printf("%d \n", pos);
}
