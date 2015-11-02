#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int car1[27];
int car2[27];
string s,s2;
void generarArreglo(){
	for(int i=0; i<s.size(); i++)
		car1[s[i]-'a']++;
	for(int i=0; i<s2.size(); i++)
		car2[s2[i]-'a']++;
}
bool noContiene(){
	for(int i=0; i<27; i++)
		if(car1[i]<car2[i])
			return true;
	return false;
}
bool automaton(){
	int lastUse=0;
	for(int i=0;i<s2.size();i++)
	{
		int pos=-1;
		for(int j=lastUse;j<s.size();j++)
		{
			if(s[j]==s2[i])
			{
				lastUse=j+1;
				pos=j;
				break;
			}	
		}
		if(pos==-1)
			return false;
	}
	return true;
}
int main(){
	cin>>s>>s2;
	memset(car1,0,sizeof(car1));
	memset(car2,0,sizeof(car2));
	generarArreglo();	
	if(s.size()<s2.size() || noContiene())
		cout<<"need tree"<<endl;
	else{
		if(s.size()==s2.size()){
			cout<<"array"<<endl;
		}
		else{
			if(automaton())
				cout<<"automaton"<<endl;
			else
				cout<<"both"<<endl;
		}
	}
	return 0;
}

