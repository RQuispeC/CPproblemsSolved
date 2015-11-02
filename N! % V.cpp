#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int tested,  m;
	long long n;
	scanf("%d", &tested);
	while(tested--)
	{
		cin>>n>>m;
		if( n>=m)
			printf("%d\n",0);
		else
		{
			//cout<<n<<" "<<m<<endl;
			long long ans=1;
			for(int i=2;i<=n;i++)
			{
				ans*=i;
				ans%=m;
			}
			cout<<ans<<endl;
		}		
	}
}
