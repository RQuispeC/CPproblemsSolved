#include<iostream>
#include<cstring>
#include<sstream>
#include<stdlib.h>
using namespace std;
int n,p,k ;
int main()
{
	cin>>n>>p>>k;
	string ans="";
	int inf=1,sup=n;
	if(p-k>1)
	{
		ans+="<< ";
		inf=p-k;
	}
	if(p+k<=n)
	{
		sup=p+k;
	}
	
	for(int i=inf;i<=sup;i++)
	{
		stringstream ss;
		ss << i;
		string str = ss.str();
		if(i==p)
			ans+="("+str+")";
		else
			ans+=str;	
		if(i<sup) ans+=" ";
	}
	if(p+k<n)
		ans+=" >>";
	cout<<ans<<endl;		
}

