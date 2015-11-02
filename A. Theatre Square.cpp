#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int  n , m, a;
	cin>>n>>m>>a;
	ll l=n/a;
	if(n%a!=0) l++;
	ll h=m/a;
	if(m%a!=0) h++;
	cout<<l*h<<endl;
}

