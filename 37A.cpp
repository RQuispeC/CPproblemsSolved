#include <bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
int main()
{
	map < int , int > mapa;
	int n;
	vector < int  > v;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(mapa[x] ==0 )
			v.push_back(x);
		mapa[x]++;	
	}
	int tot=0;
	int maxAl=0;
	for(int i=0;i<v.size();i++)
	{
		maxAl=max(maxAl, mapa[v[i]]);
	}
	cout<<maxAl<<" "<<v.size()<<endl;
}

