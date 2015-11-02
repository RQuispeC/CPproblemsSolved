#include<bits/stdc++.h>
#define	INF 1<<30
using namespace std;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vii;
typedef long long int64;
const int MAX =100000000;
vector < string > ans[4];
void eval(string  num)
{
	if(num.size()==0) return;
	string s1=num.substr(0, num.size()/2);
	string s2=num.substr(num.size()/2, num.size()/2);
	int n1=stoi(s1.c_str());
	int n2=stoi(s2.c_str());
	int x=stoi(num.c_str());
	//cout<<num<<" --> "<<x<<"  "<<n1<<" : "<<n2<<endl;
	if((n1+n2)*(n1+n2)==x)
		ans[num.size()/2 - 1].push_back(num);
}
void precalc()
{
	ans[0]=ans[1]=ans[2]=ans[3]=vector <string> ();
	for(int i=0;i*i<MAX;i++)
	{
		string s2="",s4="",s6="", s8="", tmp=to_string(i*i);
		while(tmp.size()%2!=0) tmp='0'+ tmp;
		//cout<<tmp<<" --------"<<endl;
		if(tmp.size()==2)
		{
			s2=tmp;
			s4="00"+tmp;
			s6="0000"+tmp;
			s8="000000"+tmp;
		}
		if(tmp.size()==4)
		{
			s4=tmp;
			s6="00"+tmp;
			s8="0000"+tmp;
		}
		if(tmp.size()==6)
		{
			s6=tmp;
			s8="00"+tmp;
		}
		if(tmp.size()==8)
			s8=tmp;
		eval(s2);
		eval(s4);
		eval(s6);
		eval(s8);
	}
}
int main()
{
	precalc();
	int test;
	while(scanf("%d", &test)==1)
	{
		test/=2;
		test--;
		for(int i=0;i<ans[test].size();i++)
			cout<<ans[test][i]<<endl;
	}
}

