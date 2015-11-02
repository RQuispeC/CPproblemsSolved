#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	string test;
	for(int i=0;i<10;i++)
	{
		cin>>test;
		int j=0;
		string ans="";
		while(true)
		{
			if(j>=test.size()) break;
			int con=0, t;
			for(t=j;test[t]==test[j] && t<test.size();t++)
				con++;
			ans=ans+ (char)(con+'0')+test[j] ;	
			j=t;	
		}
		cout<<ans<<endl;
	}
	for(int i=0;i<10;i++)
	{
		cin>>test;
		string ans="";
		for(int j=0;j<test.size();j=j+2)
		{
			int con=test[j]-'0';
			for(int t=0;t<con;t++)
				ans=ans+ test[j+1];
		}
		cout<<ans<<endl;
	}
}
