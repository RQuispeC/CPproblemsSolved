#include<bits/stdc++.h>
#define	INF 1<<30
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 5000005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
typedef pair< int64, int64 > pll;
int f[MAX];
bool isPrime[MAX];
int ac[MAX];
void sieve()
{
    memset(isPrime, 1, sizeof isPrime);
    isPrime[1] = isPrime[0] = 0;
    for(int i=4;i<=MAX;i+=2)
        isPrime[i]  = 0;
    for(int i=3;i*i<=MAX;i+=2)
        if(isPrime[i])
            for(int j=i*2;j<=MAX;j+=i)
                isPrime[j] = 0;
}
inline int sol(int x)
{
    if(x<=1) return 0;
    if(isPrime[x]) return 1;
    if(f[x] != -1) return f[x];
    int ans=0;
    for(int i=2;i*i;i++)
    {
        if(x%i==0)
        {
            ans = 1 + sol(x/i);
            break;
        }
    }
    return f[x] = ans;
}
int main()
{
    memset(f, -1,sizeof f);
    sieve();
    ac[0] = 0, ac[1] = 0;
    for(int i=2;i<MAX;i++)
        ac[i] = ac[i-1] + sol(i);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", ac[a] - ac[b]);
    }
}

