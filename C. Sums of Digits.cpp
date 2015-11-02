#include<bits/stdc++.h>
#define MAX  305
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
bool menor(string a, string b)
{
	if(a.size()!=b.size())
		return a.size()<b.size();
	return a<b;	
}
bool valid(string x)
{
	for(int i=0;i<x.size();i++)
		if(x[i]>'9' || x[i]<'0')
			return 0;
	return 1;		
}
int n, a[MAX];
string ans[MAX];
string sol1(int x, int numDig, int lower, string last, bool isGreater)
{
	if(numDig==1 && x<10) return string(1, (char)x+'0');
	int upper=(numDig-1)*9;
	if(!isGreater) lower=last[0]-'0';
	for(int i=lower;i<=9;i++)
		if(x-i<=upper)
			if(isGreater)
				return string(1, char(i+'0')) + sol1(x-i, numDig-1, 0, "",1 );
			else
				string tmp;
				if(i<=last[0]-'0')
					tmp=string(1, char(i+'0')) + sol1(x-i, numDig-1, 0,last.substr(1, last.size()-1), 0 );
				else
					tmp=string(1, char(i+'0')) + sol1(x-i, numDig-1, 0,last.substr(1, last.size()-1), 1 );	
				if(menor(last, tmp) && valid(tmp))
					return tmp;
	return "0";
}
bool isFullofNine(string x)
{
    for(int i=0;i<x.size();i++)
        if(x[i]!='9')
            return 0;
    return 1;       
}

string sol2(int x, int numDig, int lower)
{
	if(numDig==1 && x<10) return string(1, (char)x+'0');
	int upper=(numDig-1)*9;
	for(int i=lower;i<=9;i++)
		if(x-i<=upper)
			return string(1, char(i+'0')) + sol2(x-i, numDig-1, 0);
	return "0";
}
string  getSol(int x, string last)
{
	int lower=last[0]-'0'+1;
	int upper=last.size()*9;
	string ans="0";
	if(lower<=x && x<=upper && !isFullofNine(last))
		ans = sol1(x, last.size(), last[0]-'0', last, 0);
	if(ans=="0")
	{
		int numDig=last.size()+1;
		while(numDig*9<x)
		{
			numDig++;
		}
		ans = sol2(x, numDig, 1);
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(i==0) ans[i]=getSol(a[i], "0");
		else ans[i]=getSol(a[i], ans[i-1]);
		cout<<ans[i]<<endl;
	}
}

