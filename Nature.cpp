#include <bits/stdc++.h>
#define MAX 5005
using namespace std;
int p[MAX], numComp[MAX];
void ini(int l)
{
	for(int i=1;i<=l;i++)
		p[i]=i;
}
int find(int x)
{
	if(p[x]==x)
		return x;
	return p[x]=find(p[x]);
}
void Union(int x, int y)
{
	p[find(x)]=find(y);
}
int main()
{
	map < string , int  > mapa;
	int k, n , m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0 ) break;
		ini(n);
		memset(numComp, 0, sizeof numComp);
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			mapa[s]=i+1;
		}
		for(int i=0;i<m;i++)
		{
			string x, y;
			cin>>x>>y;
			Union(mapa[x],mapa[y]);
		}
		for(int i=1;i<=n;i++)
			numComp[find(i)]++;
		int ans=0;
		for(int i=1;i<=n;i++)
				if(p[i]==i)
					ans=max(ans, numComp[i]);
		cout<<ans<<endl;		
	}	
}
