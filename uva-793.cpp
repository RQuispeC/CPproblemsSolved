#include<iostream>
#include<cstring>
#include<sstream>
#include<stdlib.h>
#define MAX 50002
using namespace std;
int parents[MAX];
int find(int x)
{
	if(parents[x]==x) return x;
	else return parents[x]=find(parents[x]);
}
void Union(int x , int y)
{
	int rX=find(x);
	int rY=find(y);
	parents[rX]=rY;
}
int main()
{
	string s;
	getline(cin,s);
	int tested = atoi(s.c_str());
	getline(cin,s);
	bool blank=false;
	while(tested--){
		if(blank) cout<<endl;
		blank=true;
		getline(cin,s);
		int n = atoi(s.c_str());
		for(int i=0;i<n;i++)
			parents[i]=i;
			
		char op;
		int a,b, t=0,f=0;
		
		while(getline(cin,s)){
			if(s.size() == 0) break;
			stringstream in(s);
			in>>op>>a>>b;
			if(op=='c') Union(a-1,b-1);
			else{
				if(find(a-1)==find(b-1)) t++;
				else f++;
			}
			
		}
		cout<<t<<","<<f<<endl;
	}
	return 0;
}
