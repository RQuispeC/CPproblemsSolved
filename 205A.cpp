#include <bits/stdc++.h>
#define INF (int)  1e9
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
map < int, int > mapa;
map < int , int > pos;
int main()
{
	mapa.clear();
	pos.clear();
	int ans=INF;	
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d", &x);
		pos[x]=i+1;
		mapa[x]++;
		ans=min(ans, x);
	}
	//cout<<"--> "<<ans<<endl;
	if(mapa[ans]==1)
		cout<<pos[ans]<<endl;
	else
		cout<<"Still Rozdil"<<endl;
}

