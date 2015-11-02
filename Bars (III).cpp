#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
long long f[35];
long long a[35];
long long n;
int p;
bool search(long long x , int i)
{
	if(x==n || x+a[i]==n) return true;
	if(x>n) return false;
	if(x+f[i]<n) return false;
	if(x+f[i]==n) return true;
	if(i>=p-1) return false;
	return search( x+a[i], i+1) || search( x, i+1);
}
int main()
{
	int tested;
	scanf("%d", &tested);
	while(tested--)
	{
		cin>>n>>p;
		bool flag=false;
		for(int i=0;i<p;i++)
		{
			cin>>a[i];
			if(a[i]==n)
				flag=true;
		}
		if(flag || n==0)
			cout<<"YES"<<endl;
		else
		{
			for(int i=p-1;i>=0;i--)
			{
				if(i==p-1)
				{
					f[i]=a[i];
				}
				else
				{
					f[i]=a[i]+f[i+1];
				}
			}
			flag=search(0ll, 0);
			if(flag )
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}
