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
int n;
vector < string >  a;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string aux;
		cin>>aux;
		a.push_back(aux);
	}
	bool flag=true;
	char x=a[0][0];
	char y=a[0][1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j || (i+j)==n-1)
			{
				
				if(a[i][j]!=x)
					flag=false;
			}
			else
			{
				if(a[i][j]!=y )
					flag=false;
			}		
			
		}
	}
	if(x==y) flag=false;
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
}

