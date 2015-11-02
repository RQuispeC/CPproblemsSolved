//problem: http://codeforces.com/problemset/problem/264/B
#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX 100005
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define EPS 1e-9
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n, a[MAX], dp[MAX] , divi[MAX];
void update(int x, int pos)
{
    for(int i=1;i*i<=x;i++)
    {
        if(i==1) divi[x] = max(divi[x] , dp[pos]);
        else
        {
            if(x%i==0)
            {
                divi[x/i] = max(divi[x/i] , dp[pos]);
                divi[i] = max(divi[i] , dp[pos]);
            }    
        }
    }
}
int  query(int x)
{
    int ans = 0;
    for(int i=1;i*i<=x;i++)
    {
        if(i==1) ans = max(ans, divi[x]);
        else
        {
            if(x%i==0)
            {
                ans = max(ans , divi[i]);
                ans = max(ans, divi[x/i]);
            }    
        }
    }
    return ans;
}
int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    memset(divi, 0, sizeof divi);
    //dp[0]=1;
    for(int i=0;i<n;i++)
    {
        dp[i] = query(a[i]) + 1;
        update(a[i], i);
    }
    for(int i=0;i<n;i++)
        dp[n-1] = max(dp[n-1], dp[i]);
    printf("%d\n", dp[n-1]);
}

