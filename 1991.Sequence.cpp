#include<bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long ll;
string s[10];
int n;
bool canBe(int b)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<s[i].size();j++)
			if(s[i][j]-'0'>=b)
				return 0;	
	}
	return 1;		
}
int fun(string x, int b)
{
	int ans=0;
	int k=0;
	for(int i=x.size()-1;i>=0;i--)
	{
		ans=ans+((x[i]-'0')*(int)pow(b, k++));
	}
	return ans;
}
bool work(vi x)
{
	int f=x[1]-x[0];
	for(int i=1;i<n;i++)
		if(x[i]- x[i-1] != f)
			return 0;
	return 1;		
}
int main()
{
	while(cin>>n)
	{
		if(n<=0 ) break;
		for(int i=0;i<n;i++)
			cin>>s[i];
		bool f=0;	
		int b;
		for(b=1;b<=10;b++)
		{
			if(canBe(b))
			{
				vi a;
				a.clear();
				for(int i=0;i<n;i++)
					a.push_back(fun(s[i], b));
				if(work(a))
				{
					f=1;
					break;
				}
			}	
		}
		if(f)
			printf("Minimum base = %d.\n", b);
		else
			printf("No base <= 10 can be found.\n");
		
	}	
}

