#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int a[4];
vector<int> v;
int main(){
	string s;
	for(int i=0; i<4; i++){
		cin>>s;
		a[i]=s.size()-2;
	}
	int flag=false;
	for(int i=0; i<4; i++){
		int cont=0;
		for(int j=0; j<4; j++){
			if(i!=j)
				if(a[i]/2>=a[j])
					cont++;
				else break;
		}
		if(cont==3){
			v.push_back(i);
			break;
		}
	}
	for(int i=0; i<4; i++){
		int cont=0;
		for(int j=0; j<4; j++){
			if(i!=j)
				if(a[i]*2<=a[j])
					cont++;
				else break;
		}
		if(cont==3){
			v.push_back(i);
			break;
		}
	}
	if(v.size()==1)
		cout<<(char)(v[0]+'A')<<endl;
	else 
		cout<<'C'<<endl;
}

