#include<iostream>
using namespace std;
int gcd(int x, int y)
{
	if(y==0)  return x;
	else return gcd(y,x%y);
}
int main()
{
	int n;
	while(cin>>n && n!=0)
	{
		int ans=n-1;
		for(int i=2;i<n;i++)
			for(int j=i+1;j<=n;j++)
				ans+=gcd(i,j);
		cout<<ans<<endl;
	}
	return 0;
}

