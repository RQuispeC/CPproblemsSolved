#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int  a [100010];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ans=n;
	for(int i=n-1;i>0;i--)
	{
		if(a[i]>a[i-1]) ans--;
		else break;
	}	
	ans--;
	cout<<ans<<endl;	
	
}
