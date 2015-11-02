#include<bits/stdc++.h>
using namespace std;
char a [50005][25];
int n;
string s;
void built(int n, string x)
{
	int col=0, fil=0;
	for(int i=0;i<x.size();i++)
	{
		a[fil][col]=x[i];
		col++;
		if(col==n)
		{
			col=0;
			fil++;
		}
	}
}
bool valid(int i, int j)
{
	return  i>=0 && j>=0 && i<s.size()/n && j<n;
}
string f(int i, int j)
{
	string ans="";
	while(valid(i,j))
	{
		ans+=a[i][j];
		i++;
		j--;
	}
	return ans;
}
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		cin>>s;
		built(n, s);
		string ans="";
		for(int i=0;i<n;i++)
		{
			ans+=f(0,i);
		}
		for(int i=1;i<s.size()/n;i++)
		{
			ans+=f(i,n-1);
		}
		cout<<ans<<endl;
	}
}

