#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
string a[MAX];
bool f(string x, string y)
{
	string n = x+y;
	int i=0, j=n.size()-1;
	while(i<=j)
	{
		if(n[i] != n[j])
			return 0;
		i++, j--;
	}
	return 1;
}
int main()
{
	int test;
	scanf("%d", &test);
	for(int t=1;t<=test;t++)
	{
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i!= j)
				if(f(a[i], a[j]))
				{
				//	cout<<"ent"<<endl;
					ans++;
				}
			}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
