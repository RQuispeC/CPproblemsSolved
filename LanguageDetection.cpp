#include <iostream>
#include <vector>
using namespace std;
vector <string> hello;
vector <string> country;
int f(string h)
{
	int pos=-1;
	for(int i=0;i<hello.size();i++)
		if(hello[i]==h)
			pos=i;
	return pos;		
}
int main()
{
	hello.clear();
	country.clear();
	hello.push_back("HELLO");
	country.push_back("ENGLISH");
	hello.push_back("HOLA");
	country.push_back("SPANISH");
	hello.push_back("HALLO");
	country.push_back("GERMAN");
	hello.push_back("BONJOUR");
	country.push_back("FRENCH");
	hello.push_back("CIAO");
	country.push_back("ITALIAN");
	hello.push_back("ZDRAVSTVUJTE");
	country.push_back("RUSSIAN");
	string query;
	cin>>query;
	while(query!="#")
	{
		int pos=f(query);
		if(pos<0)
			cout<<"UNKNOWN"<<endl;
		else
			cout<<country[pos]<<endl;
		cin>>query;
	}
}
