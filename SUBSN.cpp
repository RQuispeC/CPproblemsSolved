#include<bits/stdc++.h> 
#define MAX 27
using namespace std;
typedef vector < int > vi;
vector < vi > lista;
vi pos;
int car1[27];
int car2[27];
string s,s2;
void generar(){
	for(int i=0; i<s.size(); i++)
	{
		car1[s[i]-'a']++;
		lista[s[i]-'a'].push_back(i);
	}	
}
void generarU()
{
	for(int i=0; i<s2.size(); i++)
		car2[s2[i]-'a']++;
}
bool noContiene(){
	for(int i=0; i<27; i++)
		if(car1[i]<car2[i])
			return true;
	return false;
}
bool posible(string x)
{
	pos.assign(MAX, 0);
	int lastPos=0;
	for(int i=0;i<x.size();i++)
	{
		int ind=lower_bound(lista[x[i]-'a'].begin()+ pos[x[i]-'a'], lista[x[i]-'a'].end(),  lastPos)-lista[x[i]-'a'].begin();
		if(lista[x[i]-'a'][ind] < lastPos )
			return false;
		else
		{
			pos[x[i]-'a']=ind+1 ; 
			lastPos=lista[x[i]-'a'][ind];
		}
	}
	return true;
}
int main(){
	string aux;
	getline(cin, aux);
	int tested=atoi(aux.c_str());
	for(int te=1;te<=tested;te++)
	{
		getline(cin, s);
		memset(car1,0,sizeof(car1));
		lista.assign(MAX, vi());
		generar();
		int query;
		getline(cin, aux);
		query=atoi(aux.c_str());
		cout<<"Case "<<te<<":"<<endl;
		for(int i=0;i<query;i++)
		{
			getline(cin, s2);
			memset(car2, 0, sizeof car2);
			generarU();
			if(noContiene())
				cout<<"NO"<<endl;
			else
				if(posible(s2) )
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
		}
	}
}

