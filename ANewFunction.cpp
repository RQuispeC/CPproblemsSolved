#include<iostream>
#include<cstring>
#include<vector>
#define MAX 2000000005
using namespace std;
long long SOD(int n)
{
	long long ans=0;
	for(int i=2;i*i<=n;i++)
	{
		int aux=n%i;
		if(aux==0)
			ans+=i;
		if(i*i!=n)
			ans+=(n/i);
	}
	return ans;
}
int main()
{
	vector <long long > a;
	a.push_back(0);
	cout<<"paso"<<endl;
	for(int i=1;i<MAX;i++)
	{
		a.push_back(a[i-1]+SOD(i));
	}
	int n;
	cout<<"paso"<<endl;
	while(cin>>n)
	{
		if(n<=0) break;
		cout<<a[n]<<endl;
	}
}
