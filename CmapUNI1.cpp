#include <iostream>
#include <vector>
#include <math.h>
#define MAX 100
using namespace std;
double DP[MAX];
int primos[MAX]; 
int expo[10000];

void cribaExtended()
{
	memset(primos,-1, sizeof(primos));
	for(int i=4 ; i<MAX ; i+=2)
		primos[i]=2;
	for(int i=3 ; i*i<MAX ; i+=2)
		if(primos[i]==-1)
			for(int j=i*i ; j<MAX ; j+=i*2)
				primos[j]=i;
}
double s(int n)
{
	memset(expo,0,sizeof(expo));
vector <int> bases;
	while(primos[n]!=-1)
	{
		expo[primos[n]]++;
		cout<<primos[n]<<endl;
		if(expo[primos[n]]==1)
			bases.push_back(primos[n]);
		n/=primos[n];	
	}
	expo[n]++;
	cout<<n<<endl;
	bases.push_back(n);
	int total=1;
	for(int i=0;i<bases.size();i++)
	{
		int exp=1; 
		for(int j=0; j<=expo[bases[i]];j++)
			exp=exp*bases[i];
		cout<<exp<<"  "<<bases[i]<<endl;
		total=total*(exp-1)/(bases[i]-1);
		cout<<total<<endl;
	} 
	cout<<total<<endl;
	return total;
}
int main()
{
	cribaExtended();
	s(20);
	s(10);
	int t,n;
	DP[0]=0;
	DP[1]=0;/*
	cout<<"kjh(8((("<<endl;
	for(int i=2;i<=MAX;i++)
	{
		DP[i]=DP[i-1]+s(i);
	}
	cout<<"poi"<<endl;
	//cin>>t;
	while(true)
	{
		for(int i=3;i<100;i++)
		{
		cout<<"##########"<<i<<endl;
		cout<<"SUMA:  "<<s(i)<<endl;
		cout<<DP[n]<<endl;
		}
		break;
	}*/
	return 0;
}
