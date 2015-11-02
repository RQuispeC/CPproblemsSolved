#include<iostream>
#include<cstring>
#include<sstream>
#include<stdlib.h>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 205
using namespace std;
bool f(vector < int > A, int to,  int a , int b, int pos )
{
	if(a==to || b==to)
		return true;
	else
	{
		if(a>to || b>to || pos<0)
			return false;
		else
			return f(A,to,a+A[pos],b,pos-1) || f(A,to,a,b+A[pos],pos-1);
	}	
}
int main()
{
	string s;
	getline(cin,s);
	int tested = atoi(s.c_str());
	while(tested--)
	{
		getline(cin,s);
		vector < int > a;
		a.clear();
		stringstream in(s);
		int tot=0;
		int aux;
		while(in>>aux)
		{
			tot+=aux;
			a.push_back(aux);
		}
		if(tot%2==0)
		{
			tot/=2;
			bool ans=f( a, tot,0,0,a.size()-1);
			if(ans)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
			cout<<"NO"<<endl;	
	}
}
