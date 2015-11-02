#include <bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
int main()
{
	int n,k,l,c,d,p,nl,np;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	int c1=k*l;
	int c2=c*d;
	c1/=nl;
	p/=np;
	int ans=min(c1,min(c2,p));
	cout<<ans/n<<endl;
}

