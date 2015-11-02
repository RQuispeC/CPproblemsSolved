#include<iostream>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		string ans="";
		for(int i=0;i<s.size();i++)
			ans+=s[i]-7;
		cout<<ans<<endl;
	}
	return 0;

}

