#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
int modulos[9];
void generarMod(){
	modulos[0]=0;
	modulos[1]=0;
	modulos[2]=3;
	int aux=5;
	for(int i=3; i<9; i++){
		modulos[i]=modulos[i-1]+aux;
		aux=aux+2;
	}
}
int main(){
	int res1=44;
	int res2=37;
	int res3=36;
	generarMod();
	ll n;
	while(cin>>n){
		if(n<10)
			cout<<(n*(n+1)/2)+(n*(n-1)/2)<<endl;
		else{
			ll n2=n/9;
			ll ans;
			if(n%9==0)
				ans=((n2*44)+1)+((n2-1)*(37)+36);
			else
				ans=((n2*44)+1)+(n2*37)+modulos[n%9];
			cout<<ans<<endl;
		}
	}
	return 0;
}

