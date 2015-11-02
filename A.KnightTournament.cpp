#include<bits/stdc++.h>
#define	INF 1e9
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 300012
#define left(x) 2*x
#define right(x) 2*x + 1
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
typedef pair< ll, ll > pll;
set<int>::iterator lt, rt;
set < int > S;
int n, m, ans[MAX];
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++)   
        S.insert(i+1);
    for(int i=0;i<m;i++)
    {
        int l, r, x;
        scanf("%d %d %d",&l, &r, &x);
        lt = S.lower_bound(l);
        rt = S.upper_bound(r);
        for(set<int>::iterator it = lt; it != rt; it++) 
        {
            int val = *it;
            if(val != x)
                ans[val] = x;
        }
        S.erase(lt, rt);
        S.insert(x);
    }
    for(int i=1;i<=n;i++)
        printf("%d ", ans[i]);
    printf("\n");
}

