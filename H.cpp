#include<bits/stdc++.h>
#define	INF 1<<30
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef pair < string , string > pss; 
typedef long long ll;
int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}
int main()
{
	int n, m;
	cin>>n>>m;
	cout<<((n*m)/gcd(n, m))/n<<endl;
}

