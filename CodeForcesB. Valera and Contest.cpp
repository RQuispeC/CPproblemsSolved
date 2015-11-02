#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n , k ,  l , r , all, part;
	cin>>n>>k>>l>>r>>all>>part;
	vector < int > ans;
	int aux=all/n;
	for(int i=0;i<n;i++)
	{
		ans.push_back(aux);
	}
	all=all-aux*n;
	if(all>0)
	{
		int i=0;
		while(all>0)
		{
			ans[i]++;
			all--;
			i=(i+1)%n;
		}
	}
	int to=0;
	for(int i=0;i<k;i++)
		to+=ans[i];
	to=part-to;
	int i=0, j=n-1;
	while(ans[i]==r) i++;
	while(ans[j]==l) j--;
	while(to>0)
	{
		if(ans[i]==r) i++;
		if(ans[j]==l) j--;
		ans[i]++;
		ans[j]--;
		to--;	
	}
	for( i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
