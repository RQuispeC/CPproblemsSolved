#include<iostream>
using namespace std;
long long f( long long n)
{
	long long ans=0;
	while(n>0)
	{
		int aux=n%10;
		ans+=(aux*aux);
		n/=10;
	}
	return ans;
}
int main()
{
	int tested;
	cin>>tested;
	for(int t=0;t<tested;t++)
	{
		long long  n;
		cin>>n;
		long long tortuga=f(n);
		long long hare=f(f(n));
		bool flag=false;
		if(tortuga==1 || hare==1) flag=true;
		int p=1;
		while(tortuga!=hare)
		{
			if(flag) break;
			p++;
			tortuga=f(tortuga);
			hare=f(f(hare));
			if(tortuga==1 || hare==1 ) flag=true;
		}
		if(!flag)
		for(int i=p;i<=2*p;i++)
		{
			tortuga=f(tortuga);
			if(tortuga==1) flag=true;
		}
		cout<<"Case #"<<(t+1)<<": ";
		if(flag) 
			cout<<n<<" is a Happy number."<<endl;
		else
			cout<<n<<" is an Unhappy number."<<endl;
	}
}


