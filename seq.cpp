#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
string alf="abcdefghijklmnopqrstuvwxyz";
vector<string> A;
map<string, int >m;
void f(int n,int x,int ma, string b){
	if(n==0)
	{
		A.push_back(b);
		m[b]=ma	;
	}	
	else{
		for(int i=x;i<alf.size();i++)
			f(n-1,i+1,ma+1,b+alf[i]);
	}
}
int main(){
	int n;
	cin>>n;
	for(int k=1;k<=n;k++){
		A.clear();
		f(n,0,0,"");
		for(int i=0;i<A.size();i++)
		{
			cout<<A[i]<<endl;
		}
	}
}
