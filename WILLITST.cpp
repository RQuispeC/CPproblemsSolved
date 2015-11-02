#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
ll pot[100];
void generarPot(){
	pot[0]=1;
	for(int i=1; i<100; i++)
		pot[i]=pot[i-1]*2;
}
bool buscar(ll n){
	for(int i=0; i<100; i++){
		if(pot[i]==n) return true;
		if(pot[i]>n) break;
	}
	return false;
}
int main(){
	ll n;
	generarPot();
	cin>>n;
	if(buscar(n))
		cout<<"TAK"<<endl;
	else 
		cout<<"NIE"<<endl;
	return 0;
}

