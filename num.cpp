#include<iostream>
#include<cmath>
using namespace std;
double fact(int x)
{
	double ans=1.0;
	for(int j=1;j<=x;j++)
		ans*=(double)j;
	return ans;	
}
int main()
{
	double  eps=1.0;
	while(eps+1>1)
		eps=eps/2;
	eps*=2;
	cout<<eps<<endl;
	double exp=0.001;
	int x;
	while(cin>>x)
	{
		cout<<x<<endl;
		double ans=0;
		double teo=pow(eps, x);
		int i=0;
		double es=2*exp;
		while(es>exp)
		{
			es=abs((teo-ans)/teo)*100;
			ans+=pow((double)x, i)/fact(i);
			i++;
		}
		cout<<ans<<endl;
	}
}

