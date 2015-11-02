#include<bits/stdc++.h>
#define MAX 10
using namespace std;
typedef vector < string > vs;
typedef pair < int , int > pii;
typedef vector < pii  > vii;
int dx1[4]={-1,-1,1,1};
int dy1[4]={-1,1,-1,1};
int dx2[4]={-2,-2,2,2};
int dy2[4]={-2,2,-2,2};
bool valid(int i, int j)
{
	return i>=0 && j>=0  && i<MAX && j<MAX;
}
int sol(vs mapa, int i, int j, int lastI, int lastJ, int murderI, int murderJ)
{
	if(valid(lastI, lastJ)) mapa[lastI][lastJ]='#';
	if(valid(murderI, murderJ)) mapa[murderI][murderJ]='#';
	int ans=0;
	for(int k=0;k<4;k++)
	{
		int attI=i+dy1[k], attJ=j+dx1[k];
		if(valid(attI,attJ) && mapa[attI][attJ]=='B')//posible matar
		{
			int nI=i+dy2[k],nJ=j+dx2[k];
			if(valid(nI, nJ) && mapa[nI][nJ]=='#') //posible mover
				ans=max(ans, 1 + sol(mapa, nI, nJ, i, j, attI, attJ));
		}
	}
	return ans;
}
int main()
{
	vs mapa;
	vii pos;
	int tested;
	cin>>tested;
	while(tested--)
	{
		mapa.clear();
		pos.clear();
		for(int i=0;i<MAX;i++)
		{
			string aux;
			cin>>aux;
			mapa.push_back(aux);
			for(int j=0;j<MAX;j++)
			{
				if(aux[j]=='W')
					pos.push_back(pii(i,j));
			}
		}
		int ans=0;
		for(int i=0;i<pos.size();i++)
			ans= max(ans, sol(mapa, pos[i].first, pos[i].second, -1,-1,-1,-1));
		cout<<ans<<endl;
	}
}

