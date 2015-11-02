#include<iostream>
#include<cstring>
using namespace std;
int n, q;
int a[55];
int pre[55][55];
void precalculo()
{
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(i==j) 
				pre[i][j]= a[i];
			else
			{
				if(a[j]<pre[i][j-1])
					pre[i][j]=a[j];
				else
					pre[i][j]=pre[i][j-1];
			}			
		}
	}
}
long long f(int query)
{
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(pre[i][j]==query)
				ans++;
		}
	}
	return ans;
}
int main() 
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	precalculo();
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int query;
		cin>>query;
		cout<<f(query)<<endl;
	}
}
