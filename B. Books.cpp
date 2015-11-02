#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long acu[100010];
	int n;
	long long t;
	cin>>n>>t;
	acu[0]=0;
	for(int i=1;i<=n;i++)
	{	
		int aux;
		cin>>aux;
		acu[i]=acu[i-1]+aux;
	}
	int ans=-1;
	for(int i=0;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			long long Aij=acu[j]-acu[i];
			if(Aij<=t)
				ans=max(ans, j-i);
		}
	}
	cout<<ans<<endl;
}

