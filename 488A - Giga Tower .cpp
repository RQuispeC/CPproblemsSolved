#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
bool get(ll x)
{
	x=abs(x);
	while(x>0)
	{
		int dig=x%10;
		if(dig==8) return 1;
		x/=10;
	}
	return 0;
}
int main()
{
	int n, ans;
	cin>>n;
	for(ll i=(ll)n+1;i<n+1e5;i++)
		if(get(i))
		{
			ans=i;
			break;
		}
	//cout<<ans<<endl;
	cout<<abs(ans-n)<<endl;
}

