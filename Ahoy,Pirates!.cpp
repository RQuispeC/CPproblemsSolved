#include<bits/stdc++.h>
#define MAX 1024005
#define NON 0
#define SET 1
#define CLR 2
#define INV 3
using namespace std;
int a[MAX], ST[3*MAX], LP[3*MAX], n;
int  oper_inv(int state)
{
	if(state == SET) return CLR;
	if(state == CLR) return SET;
	if(state == INV) return NON;
	return INV;
}
void propage(int p, int i, int j)
{
	if(LP[p]==NON) return;
	//propage to p and set new values in ST(fix p)
	if(LP[p]==SET)
		ST[p]=j-i+1;
	if(LP[p]==CLR)
		ST[p]=0;
	if(LP[p]==INV)
		ST[p]=(j-i+1) - ST[p];
	//propage to children of p
	if(i != j) // not leave
	{
		if(LP[p]==SET || LP[p]==CLR)
			LP[2*p]=LP[2*p+1]=LP[p];
		else
		{
			LP[2*p]=oper_inv(LP[2*p]);
			LP[2*p+1]=oper_inv(LP[2*p+1]);
		}
	}
	LP[p]=NON; //already fixed
}
void built(int p, int i, int j)
{
	LP[p]=NON;
	if(i==j)
		ST[p]=a[i];	
	else
	{
		int m=(i+j)/2;
		built(2*p, i, m);
		built(2*p+1, m+1, j);
		ST[p]=ST[2*p]+ST[2*p+1];
	}	
}
void upd_set(int p, int i, int j, int iq, int jq)
{
	propage(p, i, j); //fix values, p gets fixed
	if(iq>j || jq<i)
		return;
	if(i==j)//leave
	{
		ST[p]=1;
		return;	
	}
	if(iq<=i && j<=jq)
	{
		ST[p]=j-i+1;
		LP[2*p]=LP[2*p+1]=SET;
		return;
	}		
	int m=(i+j)/2;
	upd_set(2*p, i, m, iq, jq);
	upd_set(2*p+1, m+1, j, iq, jq);	
	ST[p]=ST[2*p] + ST[2*p+1];
}
void upd_clr(int p, int i, int j, int iq, int jq)
{
	propage(p, i, j); //fix values, p gets fixed
	if(iq>j || jq<i)
		return;		
	if(i==j)//leave
	{
		ST[p]=0;
		return;	
	}	
	if(iq<=i && j<=jq)
	{
		ST[p]=0;
		LP[2*p]=LP[2*p+1]=CLR;
		return;
	}
	int m=(i+j)/2;
	upd_clr(2*p, i, m, iq, jq);
	upd_clr(2*p+1, m+1, j, iq, jq);	
	ST[p]=ST[2*p] + ST[2*p+1];	
}
void upd_inv(int p, int i, int j, int iq, int jq)
{
	propage(p, i, j); //fix values, p gets fixed
	if(iq>j || jq<i)
		return;	
	if(i==j)//leave
	{
		ST[p]=(ST[p] + 1 ) % 2;
		return;
	}
	if(iq<=i && j<=jq)
	{
		ST[p]=(j-i+1) - ST[p];
		LP[2*p]=oper_inv(LP[2*p]);
		LP[2*p+1]=oper_inv(LP[2*p+1]);
		return;
	}
	int m=(i+j)/2;
	upd_inv(2*p, i, m, iq, jq);
	upd_inv(2*p+1, m+1, j, iq, jq);
	ST[p]=ST[2*p] + ST[2*p+1];	
}
int query(int p, int i, int j, int iq, int jq)
{
	propage(p, i, j); //fix values, p gets fixed
	if(iq>j || jq<i)
		return 0;
	if(iq<=i && j<=jq)
		return ST[p];
	int m=(i+j)/2;
	return query(2*p, i, m, iq, jq) + query(2*p+1, m+1, j, iq, jq);
}
int main()
{
	int tested;
	scanf("%d", &tested);
	for(int te=1;te<=tested;te++)
	{
		n=0;
		int m, p=0;
		scanf("%d", &m);
		for(int i=0;i<m;i++)
		{
			int x; string y;
			scanf("%d", &x);
			cin>>y;
			n+=(x*y.size());
			for(int j=0;j<x;j++)
			{
				for(int k=0;k<y.size();k++)
				{
					a[p++]=y[k]-'0';
				}
			}
		}
		built(1, 0, n-1);
		printf("Case %d:\n",te);
		int q;
		scanf("%d",&q);
		int qe=1;
		while(q--)
		{
			string op;
			cin>>op;
			int u, v;
			scanf("%d %d", &u, &v);
			if(op=="F") //set
				upd_set(1,0, n-1, u, v);
			if(op=="E") //clear
				upd_clr(1,0, n-1, u, v);
			if(op=="I") //invert
				upd_inv(1,0, n-1, u, v);
			if(op=="S")
				printf("Q%d: %d\n",qe++,query(1,0, n-1,u, v));
		}
	}
}



