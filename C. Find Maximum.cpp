#include<bits/stdc++.h>
using namespace std;
	int arreglo[100010];
	int acumulados[100010];
	int indices[100010];
	int indices2[100010];
	int n;
	string s;
	int aux;
int ver(){
	int maximo=0;
	for(int i=0; i<aux; i++){
		int aux2=0;
		if(indices[i]!=0) aux2=acumulados[indices[i]-1];
		aux2=aux2+indices2[i];
		maximo=max(maximo,aux2);
	}
	return maximo;
}
int ver2(){
	int suma=0;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='1')
			suma=suma+arreglo[i];
	}
	return suma;
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>arreglo[i];
	cin>>s;
	aux=0;
	int aux4=1;
	indices2[0]=0;
	for(int i=s.size()-1; i>=0; i--){
		if(s[i]=='1'){
			indices[aux++]=i;
			indices2[aux4]=indices2[aux4-1]+arreglo[i];
			aux4++;
		}
	}
	acumulados[0]=arreglo[0];
	for(int i=1; i<n; i++)
		acumulados[i]=acumulados[i-1]+arreglo[i];
	cout<<max(0,max(ver2(),ver()))<<endl;

	return 0;
}

