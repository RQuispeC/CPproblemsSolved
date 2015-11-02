#include <bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
map < string , int  > mapa;
int main()
{
	mapa.clear();
	int punt[1005];
	memset(punt, 0, sizeof punt);
	int k=1;
	int n;
	cin>>n;
	int maxi=-1;
	string ans;
	for(int i=0;i<n;i++)
	{
		string name;
		int score;
		cin>>name>>score;
		if(!mapa.count(name))
			mapa[name]=k++;
		punt[mapa[name]] += score;
		if(punt[mapa[name]] > maxi)
		{
			maxi=punt[mapa[name]];
			ans=name;
		}
	}
	//cout<<maxi<<endl;
	cout<<ans<<endl;
}

