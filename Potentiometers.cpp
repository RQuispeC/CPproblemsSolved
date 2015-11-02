#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 600005
using namespace std;
int ST[MAX];
int A[MAX];
int operation(int x , int y)
{
	return x+y;
}
void build(int n, int i , int j)
{
	if(i==j)
		ST[n]=A[i];
	else
	{
		int m=(i+j)/2;
		build(2*n,i,m);
		build(2*n+1,m+1, j );
		ST[n]=operation(ST[2*n],ST[2*n+1]);
	}	
}
void set(int n, int i , int j , int x, int v)
{
	if(i==j && i==x)
	{
		ST[n]=v;
		return ;
	}
	if(x>j || x<i )
		return;
	int m=(i+j)/2;
	set(2*n,i,m,x,v);
	set(2*n+1,m+1,j,x,v);
	ST[n]=operation(ST[2*n],ST[2*n+1]);	
}
int query(int n, int i , int j, int iq,int jq)
{
	if(iq<=i && j<=jq)
		return ST[n];
	if(iq>j || jq<i)
		return 0;
	int m=(i+j)/2;
	return operation(query(2*n,i,m,iq,jq), query(2*n+1,m+1,j,iq,jq));	
}
int main()
{
	memset(A, 0, sizeof(A));
	memset(ST, 0, sizeof(ST));
	int n;
	bool b=false;
	int ca=0;
	while(cin>>n )
	{
		if(n<=0) break;
		if(b) cout<<endl;
		b=true;
		cout<<"Case "<<++ca<<":"<<endl;
		for(int i=0;i<n;i++)
		{
			int aux;
			cin>>aux;
			A[i]=aux;
		}
		build(1,0,n-1);
		string op;
		while(cin>>op && op!="END")
		{
			if(op=="M")
			{
				int i,j;
				cin>>i>>j;
				int ans=query(1, 0, n-1,i-1,j-1);
				cout<<ans<<endl;
			}
			else
			{
				int x, v;
				cin>>x>>v;
				set(1,0,n-1,x-1,v);	
			}
		}
	}
}
