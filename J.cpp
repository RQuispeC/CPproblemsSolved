#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX 1000005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
int n,BIT[(1<<20) + 5],  next[MAX], prev[MAX], k, loser;
int limit;
void updateBIT(int pos, int val)
{
	while(pos<=limit)
	{
		BIT[pos]+=val;
		pos+=(pos & -pos);
	}
}
int queryBIT(int pos)
{
	int ans=0;
	while(pos>0)
	{
		ans+=BIT[pos];
		pos-=(pos & -pos);
	}
	return ans;
}
void BS(int kRem) //binary searh in BIT
{
	int l=0, r=limit;
	while(r-l>1)
	{
		int m= (l+r)>>1;
		if(BIT[m] == kRem)
			r=m;
		else
		{
			if(BIT[m]>=kRem)
				r=m;
			else
			{	
				kRem-= BIT[m];
				l=m;
			}	
		}	
	}
	updateBIT(r, -1);
	loser=r - 1;
}
int play(int nElem, int beg, bool flag)
{
	//get loser
	int remK = k % nElem;
	if(!flag)
	{
		int rightRem = nElem - queryBIT(beg+1);
		if(rightRem>=remK)
			BS((nElem - rightRem ) +remK);
		else
			BS(remK - rightRem);
	}
	else
	{
		int remLeft = queryBIT(beg);
		if(remLeft>=remK)
			BS(remLeft - remK +1);
		else
			BS(nElem - (remK - remLeft) +1);
	}
	next[prev[loser]] = next[loser];
	prev[next[loser]] = prev[loser];
	if(!flag)
		return next[loser];
	else
		return prev[loser];
}
void init()
{
	limit=0;
	while((1<<limit) < n) limit++;
	limit = 1<<limit;
	for(int i=0;i<=limit;i++) BIT[i] = 0;
	for(int i=0;i<n;i++)
	{
		next[i] = (i+1)%n;
		prev[(i+1)%n] = i;
		updateBIT(i+1, 1);
	}
}
int main()
{
	while(cin>>n>>k)
	{
		if(n<=0 && k<=0) break;
		init();
		int ans=0;
		bool flag=0;
		k--;
		for(int i=n;i>0;i--)
		{
			ans=play(i, ans, flag);
			flag= not flag;
		}
		printf("%d\n", ans+1);
	}
}

