#include<iostream>
using namespace std;
int main()
{
	int a[100010];
	int n, k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	bool help=true;	
	for(int i=0;i<n-1 && help;i++)
	{
		if(a[i]!=a[i+1]) 
		{
			help=false;
		}
	}	
	if(help) cout<<0<<endl;
	else
	{
		bool flag=true;
		for(int i=k-1; i<n-1 && flag ;i++)
			if(a[i]!=a[i+1]) flag=false;
		if(flag)
		{
			int ans=k-1;
			for(int i=k-1;i>0;i--)
			{
				if(a[i]!=a[i-1]) break;
				ans--;
			}
			cout<<ans<<endl;
		}
		else
			cout<<-1<<endl;
	}
}
