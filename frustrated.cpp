#include <bits/stdc++.h>
#define MOD 1000000
#define X 17
using namespace std;
string s;
typedef unsigned long long ll;
map < ll , int > memo;
ll pot[20];
string num[2510];
void generate()
{
	stringstream ss;
	pot[0]=1ll;
	for(int i=1;i<20;i++)
		pot[i] =  pot[i-1] * X;
	for(int  i =0 ;i<2510;i++)
	{
		ss.str("");
		ss.clear();
		ss<<i;
		num[i]=ss.str();
	}
}
ll hash ( string x)
{
	ll ans= 0ll;
	for(int i=0;i<x.size();i++)
	{
		ans = ans + (x[i] - '0' +1) * pot[i];
	}
	return ans;
}
string f(int a, int b, int c , int d)
{
	string ans="";
	string A = num[a];
	string B = num[b];
	string C = num[c];
	string D = num[d];
	for(int i=0;i<4 - A.size();i++)
		ans+="0";
	ans+= A;
	//cout<<ans<<endl;	
	for(int i=0;i<4 - B.size();i++)
		ans+="0";
	ans+= B;
	//cout<<ans<<endl;
	for(int i=0;i<4 - C.size();i++)
		ans+="0";
	ans+= C;
	//cout<<ans<<endl;
	for(int i=0;i<4 - D.size();i++)
		ans+="0";
	ans+= D;
	//cout<<ans<<endl;
	return ans;
}
int dp(int pos, int rem5, int rem10, int caja)
{
	if(pos ==s.size() ) return 1;
	string rep= f(pos, rem5, rem10, caja);
	ll h=hash(rep);
	if(memo.count(h)) return memo[h];
	int ans=0;
	if(s[pos]=='.')
	{
		bool f=0;
		if(rem5>=1)
		{
			ans = (ans  + dp(pos+1,rem5-1,rem10,caja+5)) %MOD;
			f=1;
		}	
		if(rem10>=1 && caja>=5)
		{
			ans = (ans +  dp(pos+1,rem5,rem10-1,caja-5)) % MOD;
			f=1;
		}
		if(!f) return memo[h] = 0;
	}
	else
	{
		if(s[pos]=='(') //poner 5
		{
			if(rem5>=1)
				ans  = (ans  + dp(pos+1,rem5-1,rem10,caja+5)) %MOD;
			else
				return memo[h] = 0;
		}
		else //poner 10
		{
			if(rem10>=1 && caja >=5)
				ans = (ans +  dp(pos+1,rem5,rem10-1,caja-5)) % MOD; 
			else
				return memo[h] = 0;	
		}
	}
	return memo[h] = ans;
}

int main()
{
	generate();
	while(getline(cin,s))
	{
		memo.clear();
		printf("%d\n",dp(0,s.size()/2,s.size()/2, 0 ) % MOD);
	}
	return 0;
}


