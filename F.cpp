#include<bits/stdc++.h>
#define	INF 1<<30
#define MAX 1000005
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
int n, ST[3*MAX], next[MAX], prev[MAX], k, loser;
void built(int u, int i, int j)
{
	if(i==j)
	{
		ST[u]=1;
		return;
	}
	int m = (i+j)>>1;
	built(2*u, i, m);
	built(2*u+1, m+1, j);
	ST[u]= ST[2*u] + ST[2*u + 1];
}
int query(int p, int i, int j, int iq, int jq)
{
	if(iq<=i && j<=jq) return ST[p];
	if(iq> j || jq <i ) return 0;
	int m= (i+j)>>1;
	return query(2*p, i, m, iq, jq) + query(2*p+1, m+1, j, iq, jq);
}
void update(int p, int i, int j, int kRem)
{
	if(i==j)
	{
		if(kRem==1)
		{
			loser=i;
			ST[p]=0;
		}	
		return;
	}
	int m = (i+j)>>1;
	int l=2*p, r=2*p+1;
	if(ST[l]>=kRem)
		update(l, i, m, kRem);
	else
		update(r, m+1, j, kRem - ST[l]);
	ST[p] = ST[l] + ST[r];
}
int play(int nElem, int beg, bool flag)
{
	//get loser
	int remK = k % nElem;
	if(!flag)
	{
		int rightRem = nElem - query(1, 0, n-1, 0, beg);
		if(rightRem>=remK)
			update(1, 0, n-1, (nElem - rightRem ) +remK);
		else
			update(1, 0, n-1, remK - rightRem);
	}
	else
	{
		int remLeft = nElem - query(1, 0, n-1, beg, n-1);
		if(remLeft>=remK)
			update(1, 0, n-1, remLeft - remK +1);
		else
			update(1, 0, n-1, nElem - (remK - remLeft) +1);
	}
	//erase from linkend list structure
	next[prev[loser]] = next[loser];
	prev[next[loser]] = prev[loser];
	if(!flag)
		return next[loser];
	else
		return prev[loser];
}
void init()
{
	for(int i=0;i<n;i++)
	{
		next[i] = (i+1)%n;
		prev[(i+1)%n] = i;
	}
	built(1, 0, n-1);
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

