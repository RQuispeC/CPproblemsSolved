#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"PERFECTION OUTPUT"<<endl;
	while(cin>>n && n>0)
	{
		long long divisors=0;
		for(int i=1;i*i<=n;i++)
		{
			int help=n/i;
			if(n%i==0 && help != 1)
			{
				divisors+=i;
				if(i!=1 && i*i!=n)
				{
					divisors+=help;
				}
			}

		}
		if(n<10)  cout<<"    ";	
		if(n>=10 && n<100) cout<<"   ";
		if(n>=100 && n<1000) cout<<"  ";
		if(n>=1000 && n<10000) cout<<" ";
		cout<<n<<"  ";
		if(divisors==n)
			cout<<"PERFECT"<<endl;
		else  if(divisors<n)
			cout<<"DEFICIENT"<<endl;
		else
			cout<<"ABUNDANT"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
