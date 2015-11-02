#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<string>
#include<map>
using namespace std;
int a[1005];
int n, k;
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int pos, min=1000000;
	for(int i=0;i<n;i++)
	{
		if(a[i]-k*i>0)
		{
			int cont=0;
			for(int j=0;j<n;j++)
			{
				if(a[j]!=a[i] - k*(i-j)) cont++;
			}
			if(cont<min)
			{
				pos=i;
				min=cont;
			}
		}	
	}
	cout<<min<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=a[pos]-(pos-i)*k)
		{
			if(a[i]>a[pos]-(pos-i)*k)
				cout<<"- "<<(i+1)<<" "<<a[i]-(a[pos]-(pos-i)*k)<<endl;
			else
				cout<<"+ "<<(i+1)<<" "<<(a[pos]-(pos-i)*k)-a[i]<<endl;	
		}
	}		
}

