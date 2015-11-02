#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MAX 300010
using namespace std;
struct element
{
	int num,left,right, frec;
	element()
	{
		left=0;
		right=-1;
		num=0;
	}
	element(int n,int f, int l, int r )
	{
		num=n;
		left=l;
		right=r;
		frec=f;
	}
};
element A[MAX];
element ST[MAX];
int n,q,k; 
element operation(element a , element b)
{
	if(a.frec>b.frec)
		return element(a.num,a.frec,min(a.left,b.left), max(a.right,b.right));
	else
		return element(b.num,b.frec,min(a.left,b.left), max(a.right,b.right));
}
void build ( int n, int i, int j)
{
	if(i==j)
		ST[n]=A[i];
	else
	{
		int m=(i+j)/2;
		build(2*n,i,m);
		build(2*n+1,m+1,j);
		ST[n]=operation(ST[2*n],ST[2*n+1]);
	}
}
int query (int n, int i, int j , int iq, int jq)
{
	if(iq<=ST[n].left && ST[n].right<=jq)
		return ST[n].frec;	
	if(iq>ST[n].right || jq<ST[n].left) return 0;	
	if(i==j) return min(jq,ST[n].right)-max(ST[n].left,iq)+1;
	int m=(i+j)/2;
	return max(query(2*n,i,m,iq,jq), query(2*n+1, m+1,j,iq,jq));
		
}
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		cin>>q;
		int aux1,aux2,frec=1;
		cin>>aux1;
		k=0;
		for(int i=1;i<n;i++)
		{
			cin>>aux2;
			if(aux2==aux1) frec++;
			if(aux2!=aux1 || i==n-1)
			{
				if(i!=n-1)
					A[k++]=element(aux1,frec,i-frec,i-1);
				if(i==n-1)
					A[k++]=element(aux1,frec,i-frec+1,i);
				aux1=aux2;
				frec=1;
			}
		}
		build(1,0,k-1);
		/*for(int i=0;i<k;i++)
			cout<<A[i].num<<" : "<<A[i].frec<<"  < "<<A[i].left<<"   "<<A[i].right<<endl;
			cout<<"<<<<<<<<<<<<<<<<<<<<<"<<endl;
			for(int i=1;i<8;i++)
				cout<<ST[i].num<<" : "<<ST[i].frec<<"  < "<<ST[i].left<<"   "<<ST[i].right<<endl;*/
		for(int i=0;i<q;i++)
		{
			int iq,jq;
			cin>>iq>>jq;
			cout<<query(1,0,k-1,iq-1,jq-1)<<endl;
		}
	}
}

