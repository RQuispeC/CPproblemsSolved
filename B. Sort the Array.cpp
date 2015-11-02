#include<bits/stdc++.h>
#define MAX 100010
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
int main()
{
	int a[MAX],b[MAX], n;
	scanf("%d", &n);
	for(int  i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		b[i]=a[i];
	}
	sort(b, b+n);
	int l=n, r=-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			l=i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]!=b[i])
		{
			r=i;
			break;
		}
	}
	if(l==n && r==-1)
	{
		cout<<"yes"<<endl;
		cout<<1<<" "<<1<<endl;
	}
	else
	{
		bool flag=1;
		//cout<<l<<" : "<<r<<endl;
		for(int i=0;i<r-l+1;i++)
		{
			if(a[l+i] != b[r-i])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			cout<<"yes"<<endl;
			cout<<l+1<<" "<<r+1<<endl;
		}	
		else
			cout<<"no"<<endl;	
	}	
	
}

