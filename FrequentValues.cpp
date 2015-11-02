#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#define MAX 300000
using namespace std;
struct node
{
    int frequency, left, right; 
    node()
    {
      frequency=0;
      left=0;
      right=0;
    }
    node(int f, int l ,int r)
    {
      frequency=f;
      left=l;
      right=r;
    }
};
node   A [MAX];
node  ST [MAX];
node operation ( node  a, node  b )
{
  if(a.frequency>b.frequency)
    return node(a.frequency,min(a.left,b.left),max(a.right,b.right));
 else 
    return node(b.frequency,min(a.left,b.left),max(a.right,b.right));   
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
int query(int n, int i, int j,int iq,int jq)
{
  if(iq<=ST[n].left && ST[n].right<=jq) return ST[n].frequency;
	if(ST[n].right <iq || jq<ST[n].left) return 0;
	if(i==j) //es hoja
	  return min(ST[n].right,jq)-max(ST[n].left,iq)+1;
	int m=(i+j)/2;
	return max(query(2*n,i,m,iq,jq), query(2*n+1,m+1,j,iq,jq));
}
int main()
{
  int n, q;
  while (cin>>n>>q)
  {
    if(n<=0) break;
    int ant=10000000,f=0, size=0;
    for(int i=0;i<=n;i++)
    {
      int aux;
	  if(i<n)cin>>aux;
	  if(aux!=ant || i==n){
		if(i>0)
			A[size++]=node ( f , i-f , i-1 );
		ant=aux;
		f=1;
	  }else
		f++;
    }
	  n=size;
    /*for(int i=0; i<n;i++)
      cout<<A[i].frequency<<"  "<<A[i].left<<"  " <<A[i].right<<"  " <<endl  ;
    cout<<"A"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>"<<endl;  */ 
    build(1, 0 , n-1);
    /*for(int i=1; i<=7;i++)
      cout<<ST[i].frequency<<"  "<<ST[i].left<<"  " <<ST[i].right<<"  " <<endl;  
    cout<<"ST"<<endl;
    cout<<">>>>>>>>>>>>>>>>>>>>>>>"<<endl;*/  
    for(int k=0;k<q;k++)
    {
      int i, j;
      cin>>i>>j;
      int ans=query(1,0,n-1, i-1, j-1);
      cout<<ans<<endl;    
    }
    //cout<<"ANS"<<endl;
    //cout<<">>>>>>>>>>>>>>>>>>>>>>>"<<endl;
  }    
}

