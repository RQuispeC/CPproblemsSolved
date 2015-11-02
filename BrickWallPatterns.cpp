#include<iostream>
using namespace std;
int main()
{
	long long f[51];
	f[0]=f[1]=1;
	for(int i=2;i<50;i++)
		f[i]=f[i-1]+f[i-2];
	int n;
	while(cin>>n && n!=0)
	{
		cout<<f[n]<<endl;
	}	
	return 0;

}

