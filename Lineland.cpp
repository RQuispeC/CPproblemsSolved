#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<set>
#include<bitset>
#define MAX 1000010
using namespace std;
struct city
{
	int pos,  c;
	city(){}
	city(int p, int ca)
	{
		pos=p;
		c=ca;
	}
	bool operator < (city x) const
	{
		return pos<x.pos;
	}
};
int aux[MAX];
city c[MAX];
int n;
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			int a, co;
			scanf("%d %d", &a, &co);
			c[i]=city(a, co);
			aux[i]=a;
		}
		sort(c, c+n);
		sort(aux, aux+n);
		int numC=-1;
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			int posi=lower_bound(aux, aux+n, c[i].pos+c[i].c)-aux;
			//cout<<i<<" :  "<<posi<<endl;
			if(posi-i-1>numC )
			{
				ans=c[i].pos;
				numC=posi-i-1;
			}
		}
		cout<<ans<<" "<<numC<<endl;
		
	}
}
