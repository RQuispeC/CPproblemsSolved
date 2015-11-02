#include<bits/stdc++.h>
#define MAX 1000005
using namespace std;
typedef long long ll;
typedef vector < int > vi;
bool isP[MAX];
vi  p;
void criba()
{
	memset (isP, true, sizeof isP);
	isP[0] = isP[1] = false;
	for (int i = 2; i * i < MAX; i==2?i++:i+=2)
	if (isP[i])
	for (int j = i * i; j < MAX; j += i) isP[j] = false;
}
void precal()
{
	p.clear();
	criba();
	for(int i=2;i<MAX;i++)
		if(isP[i])
		{
			p.push_back(i);
		}	
}
int main()
{
	precal();
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int l,r;
		cin>>l>>r;
		int posL=upper_bound(p.begin(), p.end(), l-1) - p.begin();
		int posH=upper_bound(p.begin(), p.end(), r) - p.begin();
		map < int, int > mapa;
		mapa.clear();
		vi sol;
		for(int i=posL;i<posH;i++)
		{
			if(p[i+1]<=r && p[i]>=l)
			{
				if(mapa[p[i+1] -  p[i]] == 0 )
					sol.push_back(p[i+1] -  p[i]);
				mapa[p[i+1] - p[i]]++;
			}	
		}
		int maxi = -1;
		for(int i=0;i<sol.size();i++)
			maxi=max(maxi,mapa[sol[i]]);	
		if(maxi==-1)
		{
			printf("No jumping champion\n");
			continue;
		}	
		int vec=0;
		int ans;	
		for(int i=0;i<sol.size();i++)
			if(mapa[sol[i]]==maxi)
			{
				vec++;
				ans=sol[i];
			}	
		if(vec>1)		
		{
			printf("No jumping champion\n");
			continue;
		}	
		printf("The jumping champion is %d\n", ans);
	}
}

