#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
long long arreglo[500][500];
long long acumulados[500][500];
int acumularDer[500][500];
int acumularAbaj[500][500];
void Acumular(){
	for(int i=0; i<=n; i++)
		acumulados[i][0]=acumulados[0][i]=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			acumulados[i+1][j+1]=arreglo[i][j]+acumulados[i][j+1]+acumulados[i+1][j]-acumulados[i][j];
}

int query(int i1, int j1, int i2, int j2){
	return acumulados[i2][j2]-acumulados[i1][j2]-acumulados[i2][j1]+acumulados[i1][j1];
}
void Generar(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			acumularDer[i][j]=acumularDer[i][j+n]=acumulados[i][j];
			acumularAbaj[i][j]=acumularAbaj[i+n][j]=acumulados[i][j];
		}
	}
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>arreglo[i][j];
	Acumular();
	Generar();
	int ans=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int i2=0; i2<=i; i2++)
				for(int j2=0; j2<=j; j2++)
					ans=max(ans,query(i2,j2,i,j));
	/*for(int i=1; i<n; i++){
		for(int j=n; j<n*2; j++){
			for(int i2=0; i2<=i; i2++)
				ans=max(ans,query(i2,n-1,i,j));
		}
	}*/
	cout<<ans<<endl;
	return 0;
}

