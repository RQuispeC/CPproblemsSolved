#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 300000

using namespace std;
int ST[MAX];
int A[MAX];
int N;//numero de elmento de A
void build(int n,int i,int j){
	if(i==j)// es hoja del arbol 
		ST[n]=A[i];
	else{
		int m=(i+j)/2;
		build(n*2,i,m);
		build(n*2+1,m+1,j);
		ST[n]=operation(ST[n*2],ST[n*2+1]);
	}
}
int query(int n,int i,int j,int iq,int jq){
	if(iq<=i && j<=jq)return ST[n]; // si [i,j] esta dentro de nuestro rango de consulta [iq,jq] retornar el valor de ese nodo del arbol
	if(j<iq || jq<i)return oo; // si [i,j] no esta dentro de nuestro rango de consulta [iq,jq] , retornar un valor que no afecte el resultado de la consulta por ejemplo 0 is la operacion es suma, o 1 si es producto, o infinito si la opearcion es min, o -infinito si la operacion el max
	int m=(i+j)/2;
	return operation(query(n*2,i,m,iq,jq),query(n*2+1,m+1,j,iq,jq));
}
void update(int n,int i,int j,int x,int v){
	if(i==j && i==x){ST[n]=v;return;} // si se ha encontrado el indice x
	if(x<i || j<x)return; // si el indice x no esta en nuesto rango actual [i,j] retornar sin hacer nada
	int m=(i+j)/2;
	update(n*2,i,m,x,v);
	update(n*2+1,m+1,j,x,v);
	ST[n]=operation(ST[n*2],ST[n*2+1]);
}

