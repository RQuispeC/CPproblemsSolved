#include <bits/stdc++.h>
using namespace  std;
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{	
		int n ,l;
		cin>>l>>n;
		int ans1=0, ans2=0;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d", &x);
			ans1=max(ans1, min(x, l-x));
			ans2=max(ans2, max(x, l-x));
		}
		cout<<ans1<<" "<<ans2<<endl;
	}

}

