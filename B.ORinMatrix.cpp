#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105][105], n ,m, fil[105], col[105], b[105][105] , c[105][105];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	for(int i=0;i<n;i++)
	{
		fil[i]=1;	
		for(int j=0;j<m;j++)
			fil[i]&=a[i][j];
	}
	for(int j=0;j<m;j++)
	{
		col[j]=1;	
		for(int i=0;i<n;i++)
			col[j]&=a[i][j];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			b[i][j]=fil[i] & col[j];
	for(int i=0;i<n;i++)
	{
		fil[i]=0;	
		for(int j=0;j<m;j++)
			fil[i]|=b[i][j];
	}
	for(int j=0;j<m;j++)
	{
		col[j]=0;	
		for(int i=0;i<n;i++)
			col[j]|=b[i][j];
	}
	bool ans=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j] != (fil[i] | col[j]))
			{
				ans=0;
				break;
			}
	if(ans)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<b[i][j];
				if(j+1<m) cout<<" ";
			}	
			cout<<endl;
		}
	}
	else
		cout<<"NO"<<endl;	
}
