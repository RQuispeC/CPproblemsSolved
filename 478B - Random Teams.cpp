#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll combi(int x)
{
	ll ans= ll(x)*ll(x-1) /2ll;
	return ans;	
}
int main()
{
	int n , m;
	cin>>n>>m;
	ll mini=(ll(m-(n%m))*combi(n/m) + ll(n%m)*combi(n/m + 1 ));
	ll maxi=combi(n-m+1);
	cout<<min(mini, maxi)<<" "<<max(mini, maxi)<<endl;
}
