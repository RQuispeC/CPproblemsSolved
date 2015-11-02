#include<bits/stdc++.h>
#define	INF 1e9
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define MAX 100005
#define LOGMAX 17
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
typedef pair< ll, ll > pll;
int a[MAX], res[MAX];
int main() 
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
	    scanf("%d", &a[i]);
	int worst = 0;
	for(int i = 1; i <= n; i++) 
	{
		worst = min(worst, a[i]-i);
		res[i] = i + worst;
	}
	worst = n + 1;
	for(int i = n; i >= 1; i--) 
	{
		worst = min(worst, a[i]+i);
		res[i] = min(res[i], worst-i);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, res[i]);
	printf("%d\n", ans);
	return 0;
}

