#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n, a, b;
int main()
{
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		long long w, temp;
		cin>>w;
		if(a==1)
		{
			cout<<w%b;
		}
		else
		{
			temp=(w*a)/b;
			long long aux=w-((temp*b)/a);
			long long comp=((w-aux)*a)/b;
			if(comp<temp)
				aux--;
			cout<<aux;
		}
		if(i+1<n)
			cout<<" ";
	}
	cout<<endl;
}
