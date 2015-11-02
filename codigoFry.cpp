#include<bits/stdc++.h>
using namespace std;
string s;
string  invert(string x)
{
	string ans="";
	for(int i=x.size()-1;i>=0;i--)
	{
		ans+=x[i];
	}
	return ans;
}
string sol()
{
	for(int le=2;le<=s.size();le++)
	{
		string x = s.substr(0, le-1);
		if((s.size()-le+1)%2)
			x=invert(x);
		string r=s.substr(le-1, s.size() - le +1 );
		//cout<<le<<" : "<<x<<" --> "<<r<<endl;
		s=r+x;
	}
	return s;
}

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{		
		cin>>s;
		cout<<sol()<<endl;
	}
}

