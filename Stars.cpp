#include<cstdio>
#include<iostream>
#include<cstring>
#define MAX 32010
using namespace std;
int ans[15010], BIT[MAX], n;
int f(int x)
{
	return x & -x;
}
void update(int ind, int val)
{
	while(ind<=MAX)
	{
		BIT[ind]+=val;
		ind+=f(ind);
	}
}
int query(int ind)
{
	int ans=0;
	while(ind>0)
	{
		ans+=BIT[ind];
		ind-=f(ind);
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	memset(ans, 0, sizeof ans);
	memset(BIT, 0, sizeof BIT);
	for(int i=0;i<n;i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x++;
		ans[query(x)]++;
		//cout<<x<<" "<<y<<" : "<<query(x+2)<<endl;
		update(x, 1);
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<endl;
}

