#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
using namespace std;

int invertir(int n)
{
	int inver=0;
	while(n>0)
	{
		inver+=n%10;
		n=n/10;
		inver*=10;
	}
	return inver/10; 

}
int main()
{
	bool criba[1000005];
	criba[0]=false;
	criba[1]=false;
	for(int i=2;i<=1000005;i++)
		criba[i]=true;
	for(int i=2;i*i<1000005;i++)
		for(int j=i;j*i<=1000005;j++)
			criba[i*j]=false;
	
	int num;
	while(cin>>num)
	{
		int numa=invertir(num);
		if(!criba[num])
		{
			cout<<num<<" is not prime."<<endl;
			
		}
		else
		{
			if(criba[numa] && numa!=num)
				cout<<num<<" is emirp."<<endl;
			else			
					cout<<num<<" is prime."<<endl;

		}
	}	
	return 0;
}

