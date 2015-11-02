#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string a;
	cin>>a;			
	for(int i=0;i+1<a.size();i++)
	{
		int j=i+1;
		if(a[i]==a[j] && a[i]!='.')
		{
			a[i]=a[j]='.';
			while(a[i]=='.') i--;
			while(a[j]=='.') j++;
			if(i>=0 && j<a.size())
			while(a[i]==a[j] && a[i]!='.')
			{
				if(i<0 || j>=a.size()) break;
				a[i]=a[j]='.';
				while(a[i]=='.') i--;
				while(a[j]=='.') j++;
				if(i<0 || j>=a.size()) break;
			}
			i=j-1;
		}	
	}
	string ans="";
	for(int i=0;i<a.size();i++)
		if(a[i]!='.')
			ans+=a[i];
	cout<<ans<<endl;	
}

