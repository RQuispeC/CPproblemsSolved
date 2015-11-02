#include<iostream>
#define MAX 3010
using namespace std;
int n,m;
int a[MAX];// array de n elementos
int b[MAX];// array de m elementos
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	int i=0, j=0;
	while(true)
	{
		if(i==n || j==m) break;
		if(a[i]<=b[j])
		{
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	cout<<n-i<<endl;		
}
