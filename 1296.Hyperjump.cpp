#include<bits/stdc++.h>
#define MAX 60005
using namespace std;
int n, a[MAX];
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	int ans=0, tmp = 0;
	for(int i=0;i<n;i++)
	{
		tmp=max(0, tmp + a[i]);
		ans=max(ans, tmp);
	}
	cout<<ans<<endl;
}


