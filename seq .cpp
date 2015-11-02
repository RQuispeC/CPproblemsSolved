#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
string alf="abcdefghijklmnopqrstuvwxyz";
vector<string> A;
void f(int n,int x,string b){
	if(n==0)
		A.push_back(b);
	else{
		for(int i=x;i<alf.size();i++)
			f(n-1,i+1,b+alf[i]);
	}
}
int main(){
	int n;
	cin>>n;
	for(int k=1;k<=n;k++){
		A.clear();
		f(n,0,"");
		for(int i=0;i<A.size();i++)
			cout<<A[i]<<endl;
	}
}
