#include <bits/stdc++.h>
using namespace std;
typedef vector < int > vi;
typedef pair < int , int > pii;
typedef vector < pii > vii;
typedef long long ll;
string s1="qwertyuiop",s2="asdfghjkl;",s3="zxcvbnm,./";
int buscar(string x, char y)
{
	for(int i=0;i<x.size();i++)
	{
		if(x[i]==y)
			return i;
	}
	return -1;
}
char f(char x, char dir)
{
	int pos1=buscar(s1,x);
	if(pos1 >= 0)
	{
		if(dir=='R')
			return s1[pos1-1];
		else
			return s1[pos1+1];	
	}
	int pos2=buscar(s2,x);
	if(pos2>=0)
	{
		if(dir=='R')
			return s2[pos2-1];
		else
			return s2[pos2+1];			
	}
	int pos3=buscar(s3,x);
	if(pos3>=0)
	{
		if(dir=='R')
			return s3[pos3-1];
		else
			return s3[pos3+1];
	}
}
int main()
{	
	char dir;
	string bus;
	cin>>dir>>bus;
	string ans="";
	for(int i=0;i<bus.size();i++)
	{
		ans+=f(bus[i] , dir);
	}	
	cout<<ans<<endl;
}

