#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MAX 205
using namespace std;
int n,m;
int a[MAX];
int acu[MAX];
void generate()
{
	acu[0]=0;
	for(int i=1;i<=n;i++)
	{
		acu[i]=acu[i-1]+a[i-1];
	}
}
int main()
{
	int tested;
	cin>>tested;
	while(tested--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>a[i];
		generate();
		int ans=0;
		for(int i=0;i+m<=n;i++)
		{
			//cout<<"**  "<<acu[i+m]-acu[i]<<endl;
			ans=max(ans, acu[i+m]-acu[i]);
		}
		for(int i=n-m+1;i<n;i++)
		{
			int j=(i+m)%n;
			ans=max(ans, acu[j]+acu[n]-acu[i]);
			//cout<<"***  "<<acu[j]<<" "<<acu[n]<<" "<<acu[i]<<endl;
		}
		cout<<ans<<endl;
	}
}

