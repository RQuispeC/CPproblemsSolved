#include<bits/stdc++.h>
#define MAX 100
using namespace std;
long long x[MAX];
int sumDig(long long a)
{
	if(a<=0) return a;
	int ans=0;
	while(a>0)
	{
		ans+=(a%10);
		a=a/10;
	}
	return ans;
}
int main()
{
	int a, b, c;
	cin>>a>>b>>c;
	int cont=0;
	vector < long long  > ans;
	ans.clear();
	for(int i=0;i<MAX;i++)
	{
		x[i]=b*(long  long )(pow(i,a)) + c;
		if(sumDig(x[i]) == i && x[i] < 1e9)
			ans.push_back(x[i]);
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	if(ans.size())
		cout<<endl;
	return 0;	
}
