#include<bits/stdc++.h>
using namespace std;
int valo[1000];
unsigned long long f(string x)
{
	unsigned long long ans=0ll;
	for(int i=0;i<x.size();i++)
	{
		ans+=(unsigned long long )(valo[x[i]]);
	}
	return ans;	
}
int main()
{
	
	string s;	
	int test;
	getline(cin, s);
	test=atoi(s.c_str());
	while(test--)
	{
		memset(valo, 0, sizeof valo);
		int n;
		getline(cin, s);
		n=atoi(s.c_str());
		for(int i=0;i<n;i++)
		{
			getline(cin, s);
			stringstream in(s);
			unsigned char x; int val;
			in>>x>>val;
			in.clear();
			valo[(int)x]=val;
		}
		unsigned long long ans=0ll;
		getline(cin, s);
		n=atoi(s.c_str());
		for(int i=0;i<n;i++)
		{
			getline(cin, s);
			stringstream in(s);	
			string word;
			while(in>>word)	
			{
				ans+=f(word);
			}
			in.clear();
		}
		unsigned long long  dol =ans/100ll;
		unsigned long long  cent =ans%100ll;
		 cout<<dol<<"."<<(cent<10ll?"0":"")<<cent<<"$"<<endl;
	}	
}

