#include<bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef long long ll;
int n,m, a[MAX], l[MAX], r[MAX], ac[MAX][MAX];
ll ans;
char grip[MAX][MAX];
ll getSol()
{
	stack < int >  q;
	l[0]=-1;
	q.push(0);
	for(int i=1;i<m;i++)
	{
		while(!q.empty() && a[q.top()]>=a[i])
		{
			q.pop();
		}
		if(q.empty()) l[i]=-1;
		else l[i]=q.top();
		q.push(i);
	}
	stack < int  > qp;
	swap(qp, q);
	r[m-1]=m;
	q.push(m-1);
	for(int i=m-2;i>=0;i--)
	{
		while(!q.empty() && a[q.top()]>=a[i])
		{
			q.pop();
		}
		if(q.empty()) r[i]=m;
		else r[i]=q.top();
		q.push(i);
	}
	ll tmpAns=0ll;
	for(int i=0;i<m;i++)
		tmpAns=max(tmpAns, ll(r[i] - l[i]-1)*ll(a[i]));
	return tmpAns;
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d %d", &n, &m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>grip[i][j];
		for(int i=0;i<m;i++)
			ac[0][i]=(grip[0][i]=='F'?1:0);
		for(int i=1;i<n;i++)	
			for(int j=0;j<m;j++)
				if(grip[i][j]=='F')
					ac[i][j]=ac[i-1][j]+1;
				else
					ac[i][j]=0;	
		ans=0ll;			
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				a[j]=ac[i][j];
			ans=max(ans, getSol());
		}
		printf("%lld\n", ans*3ll);
	}
}

