#include <iostream>
#include <cstring>
#define MAX 105
using namespace std;
bool f(int n, int k)
{
	bool digits[10];
	memset(digits,false,sizeof(digits));
	if(n==0)
		digits[0]=true;
	else
	{
		while(n>0)
		{
			digits[n%10]=true;
			n/=10;
		}
	}
	bool ans=true;
	for(int i=0;i<=k;i++)
	{
		if(!digits[i])
		{
			ans=false;
			break;
		}
	}
	return ans;
	
}
int main()
{
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int aux;
		cin>>aux;
		if(f(aux,k))
			ans++;
	}
	cout<<ans<<endl;
}

