#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
string ter(int x)
{
	string ans="";
	while(x>=3)
	{
		int m=x%3;
		x/=3;
		ans+=(char)('0'+m);
	}
	if(x>0)
		ans+=(char)('0'+x);
	string aux=ans;
	ans="";
	for(int i=aux.size()-1;i>=0;i--)
		ans+=aux[i];		
	return ans;
}
int main()
{
	int A, C;
	cin>>A>>C;
	string a,c;
	a=ter(A);
	c=ter(C);
	int az=a.size();
	int cz=c.size();
	int li=max(az, cz)-  min(az, cz);
	if(a.size()>c.size())
	{
		for(int i=0;i<li;i++)
			c='0'+c;
	}
	else
	{
		for(int i=0;i<li;i++)
			a='0'+a;
	}				
	string b="";
	for(int i=0;i<a.size();i++)
	{
		if(c[i]>=a[i])
		{
			int tm=c[i]-a[i];
			b+=(char)(tm+'0');
		}
		else
		{
			int ci=c[i]-'0'+3;
			int ai=a[i]-'0';
			int tm=ci-ai;
			b+=(char)(tm+'0');
		}	
	}

	long long ans=0;
	int k=0;
	for(int i=b.size()-1;i>=0;i--)
		ans+=((long long) pow(3,k++)*(long long)(b[i]-'0'));
	cout<<ans<<endl;	
}

