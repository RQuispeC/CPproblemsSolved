#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define MAX 150000
using namespace std;
int A[MAX];
int ST[MAX];
int STsuma[MAX];
int n, m;
void buildSuma(int n, int i, int j)
{
	if(i==j)
		STsuma[n]=A[i];
	else
	{
		int m=(i+j)/2;
		buildSuma(2*n, i, m);
		buildSuma(2*n+1, m+1, j);
		STsuma[n]= STsuma[2*n]+STsuma[2*n+1];
	}	
}
void build(int n, int i, int j)
{
	if(i==j)
		ST[n]=A[i];
	else
	{
		int m=(i+j)/2;
		build(2*n, i, m);
		build(2*n+1, m+1, j);
		ST[n]= max(STsuma[n], max(ST[n*2], ST [2*n+1]));
	}	
}
int query(int n, int i , int j, int iq, int jq)
{
	if(iq<=i && j<=jq) return ST[n];
	if(j<iq || jq<i ) return -2000000000;
	int m=(i+j)/2;
	int q1=query(2*n, i, m, iq, jq);
	int q2=query( 2*n+1, m+1, j, iq, jq);
	return max( q1, q2 ) ;
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &A[i]);
	buildSuma(1, 0, n-1);
	build(1, 0, n-1);
	scanf("%d", &m);
	for(int i=0;i<m;i++)
	{
		int iq, jq;
		scanf("%d %d", &iq, &jq);
		printf("%d\n" , query(1, 0,n-1, iq-1, jq-1));
	}	
}

