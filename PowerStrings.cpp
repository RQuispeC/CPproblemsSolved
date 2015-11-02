#include<bits/stdc++.h>
using namespace std;
string s;
vector < int > div(int x)
{
	vector < int > ans;
	ans.clear();
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ans.push_back(i);
			if(i*i !=x)
				ans.push_back(x/i);
		}
	}
	return ans;
}
string sPow(string x, int e)
{
	string ans="";
	for(int i=0;i<e;i++)
		ans+=x;
	return ans;	
}
int main()
{
	while(cin>>s)
	{
		if(s==".") break;
		vector < int >	v;
		v=div(s.size());
		sort(v.begin(), v.end());
		int ans=0;
		for(int i=0;i<v.size();i++)
		{
			string sp=sPow(s.substr(0,v[i]), (int)s.size()/v[i]);
			if(sp==s)
			{
				ans=max(ans, (int)s.size()/v[i]);
				break;
			}	
		}
		cout<<ans<<endl;
	}
}

