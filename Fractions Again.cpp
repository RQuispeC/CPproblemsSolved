#include<bits/stdc++.h>
#define	INF 1<<30
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
int k;
void sol()
{
	vii ans;
	ans.clear();
	for(int x=k+1;x<=2*k;x++)
	{
		if((x*k)%(x-k)==0)
		{
			ans.push_back(pii((x*k)/(x-k),x));
			if(ans[ans.size()-1].first < ans[ans.size()-1].second)
				swap(ans[ans.size()-1].first, ans[ans.size()-1].second);
		}
	}
	sort(ans.rbegin(), ans.rend());
	printf("%d\n", (int)ans.size());
	for(int i=0;i<ans.size();i++)
		printf("1/%d = 1/%d + 1/%d\n",k, ans[i].first, ans[i].second);
}
int main()
{	
	while(scanf("%d", &k)==1)
		sol();
}

