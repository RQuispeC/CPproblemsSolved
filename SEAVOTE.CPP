#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n, sum=0;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d", &x);
			sum+=x;
		}
		int mini=(sum - n + 1);
		int maxi=sum;
		bool f=0;
		if(mini<= 100 && 100<=maxi)
			f=1;
		if(f)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;		
	}
}

