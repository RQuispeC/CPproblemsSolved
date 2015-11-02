#include<bits/stdc++.h>
using namespace std;
string swapeo(string x, int i, int j)
{
	string ans=x;
	swap(ans[i], ans[j]);
	return ans;
}
int main()
{
	int test;
	scanf("%d", &test);
	for(int te=1;te<=test;te++)
	{
		printf("Case #%d: ", te);
		string x;
		cin>>x;
		string mini=x, maxi=x;
		for(int i=0;i<x.size();i++)
			for(int j=i+1;j<x.size();j++)
			{
				string nx=swapeo(x, i, j);
				if(nx[0]!= '0')
				{
					//cout<<nx<<endl;
					maxi=max(maxi, nx);
					mini=min(mini, nx);
				}	
			}
		cout<<mini<<" "<<maxi<<endl;	
	}
}

