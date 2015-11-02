#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, k;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int op;
		cin>>op;
		if(op==2 && k>0 ) k--;
		else if(op==2 && m>0 ) m--;
		else if(op==1 && m>0 ) m--;
		else ans++;
	}
	cout<<ans<<endl;
}
