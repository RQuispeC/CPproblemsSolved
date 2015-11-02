#include<cstring>
#include<iostream>
using namespace std;
bool validate(string x)
{
	int con=0;
	int pos=-1;
	for(int i=0;i<x.size();i++)
		if(x[i]=='@') con++, pos=i;
		else if(x[i]==' ' || x[i]==',') return false;
	if(con!=1) return false;
	con=0;
	for(int i=pos;i<x.size();i++)
		if(x[i]=='.') con++;
	if(con==0) return false;
	return true;
}
int main()
{
	string s;
	while(getline(cin, s))
		validate(s)?cout<<"valido"<<endl: cout<<"invalido"<<endl;
}
