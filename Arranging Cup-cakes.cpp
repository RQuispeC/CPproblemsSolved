#include<iostream>
#include<cmath>
using namespace std;
int t, n;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=1000000000;
		for(int i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				int aux=n/i - i;
				if(aux<0) aux*=-1;
				if(aux<ans) ans=aux;
			}
		}
		cout<<ans<<endl;
	}
}
