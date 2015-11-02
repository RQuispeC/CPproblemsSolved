#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 300000
using namespace std;
int ST[MAX];             //arreglo del segmen tree
int A[MAX];              //arreglo original         
int operation (int x, int y)
{
  return (x*y);
}
void build(int n,int i,int j){
	if(i==j) 
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
	if(j<iq || jq<i) return 1; // si [i,j] no esta dentro de nuestro rango de consulta [iq,jq] , retornar un valor que no afecte el resultado de la consulta por ejemplo 0 is la operacion es suma, o 1 si es producto, o infinito si la opearcion es min, o -infinito si la operacion el max
	int m=(i+j)/2;
	return operation(query(n*2,i,m,iq,jq),query(n*2+1,m+1,j,iq,jq));
}
void update(int n,int i,int j,int x,int v){
	if(i==j && i==x)
	{
	  ST[n]=v;return;        // si se ha encontrado el indice x
	} 
	if(x<i || j<x)
	  return; // si el indice x no esta en nuesto rango actual [i,j] retornar sin hacer nada
	int m=(i+j)/2;
	update(n*2,i,m,x,v);
	update(n*2+1,m+1,j,x,v);
	ST[n]=operation(ST[n*2],ST[n*2+1]);
}
//para llamar alos metodos tenemos:
//build(1,0,N-1);
//query(1,0,N-1,qleft,qright);
//update(1,0,N-1,index,val);
//donde N es el numero de elementos
int main()
{
  memset(A,1,sizeof(A));
  memset(ST, 0 ,sizeof(ST));
  int t,q;
  while(cin>>t>>q)
  {
    for(int i=0;i<t;i++)
    {
      int o;
      cin>>o;
      if(o>0)
        A[i]=1;
      else if(o==0) A[i]=0;
      else A[i]=-1;         
    }
    build(1,0,t-1);
    string ans="";
    for(int i=0;i<q;i++)
    {
      char aux;
      cin>>aux;
      if(aux=='C')
      {
            int i,v;           
            cin>>i>>v;
            if(v>0) v=1;
            else if(v==0) v=0;
            else v=-1;
            update(1,0,t-1,i-1,v);
      }
      else
      {
            int i,j;
            cin>>i>>j;
            int k=query(1,0,t-1,i-1,j-1);
            if(k>0) ans+="+";
            else if(k==0) ans+="0";
            else  ans+="-";
            
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}

