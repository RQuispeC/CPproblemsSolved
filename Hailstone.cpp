#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
	if(n%2==0)
		return n/2;
	else
		return n*3+1;	
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int t, n;
		scanf("%d %d", &t, &n);
		int ans=n;
		while(n!=1)
		{
			n=f(n);
			//cout<<"-->  "<<n<<endl;
			ans=max(ans, n);
		}
		printf("%d %d\n",t,  ans);
	}
}
