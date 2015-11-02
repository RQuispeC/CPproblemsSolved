#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct node{
  int a0,a1,a2;
  int sum;
  node(){
    a0=1;
    a1=0;
    a2=0;
    sum=0;
  }
} ST[3000000];
void propague(int n){  
  if(ST[n].sum%3==1){
    int t=ST[n].a2;
    ST[n].a2=ST[n].a1;
    ST[n].a1=ST[n].a0;
    ST[n].a0=t;
  }else if(ST[n].sum%3==2){
    int t=ST[n].a1;
    ST[n].a2=ST[n].a0;
    ST[n].a1=ST[n].a2;
    ST[n].a0=t;
  }
  ST[n*2].sum+=ST[n].sum;
  ST[n*2+1].sum+=ST[n].sum;
  ST[n].sum=0;
}
void build(int n,int i,int j){
  if(i==j)
    ST[n]=node();
  else{
    int m=(i+j)/2;
    build(n*2,i,m);
    build(n*2+1,m+1,j);
    ST[n].a0=ST[n*2].a0+ST[n*2+1].a0;
    ST[n].a1=ST[n*2].a1+ST[n*2+1].a1;
    ST[n].a2=ST[n*2].a2+ST[n*2+1].a2;
  }
}
void update(int n,int i,int j,int iq,int jq){
  propague(n);
  if(iq<=i && j<=jq){ST[n].sum++;propague(n);return;}
  if(j<iq || jq<i)return;
  int m=(i+j)/2;
  update(n*2,i,m,iq,jq);
  update(n*2+1,m+1,j,iq,jq);
  ST[n].a0=ST[n*2].a0+ST[n*2+1].a0;
  ST[n].a1=ST[n*2].a1+ST[n*2+1].a1;
  ST[n].a2=ST[n*2].a2+ST[n*2+1].a2;
}
int query(int n,int i,int j,int iq,int jq){
  propague(n);
  if(iq<=i && j<=jq)return ST[n].a0;
  if(j<iq || jq<i)return 0;
  int m=(i+j)/2;
  return query(n*2,i,m,iq,jq)+query(n*2+1,m+1,j,iq,jq);
}
int main(){
  int N,Q,op,a,b;
  cin>>N>>Q;
  build(1,0,N-1);
  /*for(int j=1;j<8;j++){
    printf("(%d) [%d,%d,%d]\n",j,ST[j].a0,ST[j].a1,ST[j].a2);
  }
  printf("\n");*/
  for(int i=0;i<Q;i++){
    cin>>op>>a>>b;
    if(op==0) update(1,0,N-1,a,b);
    else cout<<query(1,0,N-1,a,b)<<endl;
    /*for(int j=1;j<8;j++){
      printf("(%d) [%d,%d,%d] %d\n",j,ST[j].a0,ST[j].a1,ST[j].a2,ST[j].sum);
    }
    printf("\n");*/
  }
}
