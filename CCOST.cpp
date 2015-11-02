#include <bits/stdc++.h>
#define MAX 100005
#define MAXn 10000005
using namespace std;
typedef long long ll;
typedef pair < int , int > pii;
typedef pair < pii, int > piii;
int n, q, BIT [MAXn];
piii totP[3*MAX], p[MAX];
pair < pii , pii > query[MAX];
bool orden (piii x, piii y)
{
	if(x.first.second != y.first.second)
		return x.first.second < y.first.second;
	return x.first.first < y.first.first;
}
int read(int pos)
{
	int ans = 0;
	while(pos>0)
	{
		ans+=BIT[pos];
		pos-=(pos & -pos);
	}
	return ans;
}
void update(int pos, int val)
{
	while(pos < MAXn)
	{
		BIT[pos]+=val;
		pos+=(pos & -pos);
	}
}
map < pii, int > sol; 
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		memset(BIT, 0,sizeof BIT);
		sol.clear();
		scanf("%d", &n);
		int k=0;
		for(int i=0;i<n;i++)
		{
			int x,y,v;
			scanf("%d %d %d", &x, &y, &v);
			x+=2,  y+=2;
			p[i]=piii(pii(x,y),v);
			totP[i]=p[i];
		}	
		k=n;
		scanf("%d", &q);
		for(int i=0;i<q;i++)
		{
			int x1 , y1, x2,y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			x1+=2, y1+=2,x2+=2, y2+=2;
			totP[k++]=piii(pii(x1-1,y1-1),-1);
			totP[k++]=piii(pii(x2,y2),   -1);
			totP[k++]=piii(pii(x1-1,y2), -1);
			totP[k++]=piii(pii(x2,y1-1), -1);		
			query[i]=make_pair(pii(x1,y1), pii(x2,y2));
		}
		sort(totP, totP + k, orden);
		for(int i=0;i<k;i++)
		{
			if(totP[i].second != -1)
			{
				update(totP[i].first.first,totP[i].second);
			}
			else//get query
			{
				sol [ totP[i].first ] = read(totP[i].first.first);
			}
		}	
		for(int i=0;i<q;i++)
		{
			int x1=query[i].first.first;
			int y1=query[i].first.second;
			int x2=query[i].second.first;
			int y2=query[i].second.second;
			printf("%d\n", sol[pii(x2,y2)] - sol[pii(x2, y1-1)] - sol[pii(x1-1,y2)]  + sol[pii(x1-1,y1-1)] );
		}
	}
}
