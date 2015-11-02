#include<bits/stdc++.h>
using namespace std;
bool isPal(string x)
{
	int i=0,j =x.size()-1;
	while(i<j)
	{
		if(x[i] != x[j])
			return 0;
		i++, j--;	
	}
	return 1;
}
string sol(string x)
{
	int i=0,j =x.size()-1;
	while(i<j)
	{
		if(x[i] != x[j])
			break;
		i++, j--;	
	}
	string s1="",s2="";
	for(int k=0;k<x.size();k++)
	{
		if(k==i)
			s1+=x[j];
		s1+=x[k];
		s2+=x[k];
		if(k==j)
			s2+=x[i];	
	}
	//cout<<i<<" "<<j<<endl<<s1<<" "<<s2<<endl;
	if(isPal(s1)) return s1;
	if(isPal(s2)) return s2;
	return "NA";
	
}
int main()
{
	string s;
	cin>>s;
	cout<<sol(s)<<endl;
}

