#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
vi ans;
void sol(vi num, int h)
{
	if(num.size()==0) return;
	if(h==1)
	{
		ans.push_back(num[0]);
		return;	
	}	
	int pos=max(0,(int)num.size()-((1<<(h-1)) - 1) - 1);
	ans.push_back(num[pos]);
	vi left, right;
	left.clear(), right.clear();
	for(int i=0;i<pos;i++)
		left.push_back(num[i]);
	for(int i=pos+1;i<num.size();i++)
		right.push_back(num[i]);
	sol(left, h-1);
	sol(right, h-1);
}
int main()
{
	vi tmp;
	int n, h, test=1;
	while(scanf("%d %d", &n, &h)==2)
	{
		if(n<=0 && h<=0) break;
		if(n > (1<<h)-1 )
		{
			printf("Case %d: Impossible.\n", test++);
			continue;
		}
		tmp.clear();
		for(int i=1;i<=n;i++)
			tmp.push_back(i);
			
		ans.clear();	
		sol(tmp, h);
		
		printf("Case %d:", test++);
		for(int i=0;i<n;i++)
			printf(" %d", ans[i]);
		printf("\n");
	}	
}

