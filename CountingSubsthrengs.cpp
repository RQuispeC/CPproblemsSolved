#include <bits/stdc++.h>
#define MAX (int)1e6 + 5
typedef long long ll;
using namespace  std;
ll memo[MAX][3][2];
bool f(char x)
{
	return '0'<=x && x<='9';
}
string norm(string x)
{
	string ans="";
	for(int i=0;i<x.size();i++)
		ans+=(char(((x[i]-'0')%3)+'0'));
	return ans;
}
ll dp(int pos, int sum,int isBegin, string x, int posIni)
{
	if(pos==x.size()) 
	{
		if(!isBegin && sum%3==0)
			
			return 1ll;
		return 0ll;
	}	
	if(memo[pos+posIni][sum][isBegin] != -1)
		return 0;
	ll ans=0ll;
	if(!isBegin && sum%3==0)
		ans++;
	ans+=dp(pos+1, (sum+x[pos]-'0')%3,0,x, posIni);
	ans+=dp(pos+1, 0,1,x,posIni);
	cout<<pos<<" ** "<<sum<<" -- "<<isBegin<<" --> "<<ans<<endl; 
	return memo[pos+posIni][sum][isBegin]=ans;
}
ll count(string x, int i)
{
	ll ans=dp(0,0,1, x, i );
	cout<<x<<" : "<<ans<<endl;
	return ans;
}
int main()
{
	vector < pair < int , string > > v;
	string s;
	while(cin>>s)
	{	
		v.clear();
		memset(memo, -1, sizeof memo);
		string subs="";
		for(int i=0;i<s.size();i++)
		{
			if(f(s[i]))
			{
				subs+=s[i];
				if(i==s.size()-1 && subs.size() != 0)
					v.push_back(make_pair(i-subs.size()+1,subs));
			}
			else
			{
				if(subs.size() != 0)
				{
					v.push_back(make_pair(i-subs.size(),subs));
					subs="";
				}
			}
		}
		ll ans=0ll;
		for(int i=0;i<v.size();i++)
		{
			ans+=count(v[i].second, v[i].first);
		}	
		cout<<ans<<endl;
	}
}
