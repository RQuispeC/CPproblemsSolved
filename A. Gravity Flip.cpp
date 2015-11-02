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
int main()
{
	int n;
	cin>>n;
	vector < int  > a ;
	a.clear();
	for(int i=0;i<n;i++)
	{
		int aux;
		cin>>aux;
		a.push_back(aux);
	}
	sort(a.begin(), a.end());
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		if(i+1<n)
			cout<<" ";
	}
	cout<<endl;	
}

