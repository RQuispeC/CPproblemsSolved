#include <bits/stdc++.h>
#define MAX (int) 1e5 + 5
using namespace std; 
int p[MAX], numComp[MAX], node;
map < string, int > mapa;
void ini(int l)
{
	for(int i=1;i<=l;i++)
	{
		p[i]=i;
		numComp[i]=1;
	}	
}
int find(int x)
{
	if(p[x]==x)
		return x;
	return p[x]=find(p[x]);
}
void Union(int x , int y)
{
	int X=find(x);
	int Y=find(y);
	int ans=numComp[X];
	if(X!=Y)
	{
		p[X]=Y;
		numComp[Y]+=numComp[X];
		ans=numComp[Y];
	}
	cout<<ans<<endl;
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		mapa.clear();
		ini(MAX);
		int rel;
		node=1;
		scanf("%d", &rel);
		for(int r=0;r<rel;r++)
		{
			string X,Y;
			cin>>X>>Y;
			if(!mapa.count(X))
				mapa[X]=node++;
			if(!mapa.count(Y))
				mapa[Y]=node++;
			Union(mapa[X], mapa[Y]);
		}
	}
}

