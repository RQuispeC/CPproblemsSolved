#include <iostream>
#include <string.h>
#include<algorithm>
#include<cstring>
#define MAX 110
using namespace std;
long long  Machos[MAX];
long long  Hembras[MAX];
int main()
{
	Machos[0]=0;
	Hembras[0]=1;
	for(int i=1;i<110;i++)
	{
		Machos[i]=Hembras[i-1]+Machos[i-1];
		Hembras[i]=Machos[i-1]+1;
	}
	int n;
	cin>>n;
	while(n>=0)
	{
		cout<<Machos[n]<<" "<<Machos[n]+Hembras[n]<<endl; 
		cin>>n;
	}
	return 0;	
}
