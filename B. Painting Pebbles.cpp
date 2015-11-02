#include<bits/stdc++.h>
#define INF 1<<30
#define MAX  105
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
int n , m , a[MAX];
vector < vi > ans;
int main()
{
	ans.assign(MAX, vi());
	scanf("%d %d", &n, &m);
	int mini=INF;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		mini=min(mini, a[i]);
	}
	bool f=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<mini;j++)
			ans[i].push_back(1);
	}
	int k=1;
	while(1)
	{
		bool getOut=1;
		for(int i=0;i<n;i++)
			if(ans[i].size()<a[i])
			{
				getOut=0;
				ans[i].push_back(k);
			}
			
		if(getOut) break;
		k++;
	}
	k--;
	cout<<k<<endl;
	if(k<=m)
	{
		printf("YES\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<ans[i].size();j++)
				printf("%d ", ans[i][j]);
			printf("\n");
		}
	}
	else
		printf("NO\n");
}

