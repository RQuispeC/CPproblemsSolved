#include<iostream>
#include<algorithm>
#include<cstring>
#include <set>
using namespace std;
long long final[10][10001];
long long temp[10];
void One (int n)//descompone un numero
{
	memset(temp,0,sizeof(temp));
	while(n>0)
	{
		temp[n%10]++;
		n/=10;
	}
}
void generate()
{
	memset(final,0,sizeof(final));
	for(int i=1;i<=10001;i++)
	{
		One(i);
		for(int j=0;j<10;j++)
		{
			final[j][i]=final[j][i-1]+temp[j];	
		}
	}
}
int  main()
{
	generate();
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		for(int i=0;i<10;i++)
		{
			if (i > 0) cout<<" ";
			cout<<final[i][n];
		}
		cout<<endl;
	}
	return 0;
}
