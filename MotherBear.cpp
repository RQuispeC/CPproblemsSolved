#include <bits/stdc++.h>
using namespace  std;
string rever(string x)
{
	string ans="";
	for(int i=x.size() - 1;i>=0;i--)
		ans+=x[i];
	return ans;
}
int main()
{
	string s;
	while(getline(cin, s))
	{
		if(s=="DONE") break;
		string ns="";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='a' && s[i]<='z')
				ns+=s[i];
			if(s[i]>='A' && s[i]<='Z')			
				ns+=tolower(s[i]);
		}
		string rs=rever(ns);
		bool f=1;
		for(int i=0;i<ns.size();i++)
			if(ns[i] != rs[i])
			{
				f=0;
				break;
			}
		if(f)
			cout<<"You won't be eaten!"<<endl;
		else
			cout<<"Uh oh.."<<endl;
	}

}

