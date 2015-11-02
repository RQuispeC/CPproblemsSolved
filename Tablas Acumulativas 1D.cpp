#include <iostream>
#include <cstring>
#define MAX 100000
using namespace std;
int tabla[MAX];
int a[MAX];
int dp(int i)
{
	if(i>=MAX || i<0 ) return 0;
	if(tabla[i]!=-1) return tabla[i];
	return tabla[i]=a[i]+dp(i-1);	
}
int query(int i, int j)
{
	return tabla[j]-tabla[i];
}
int main()
{
	memset(tabla,-1, sizeof tabla);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int i,j;
	cin>>i>>j; // 1<=i<=n && 1<=j<=n && i<=j
	tabla[0]=a[0];
	dp(n-1);
	cout<<query(i-1,j-1)<<endl;
}
