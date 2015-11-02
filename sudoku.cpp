#include<bits/stdc++.h>
#define MAX 90
using namespace std;
typedef vector < int > vi;
int n , empty, a[9][9], ans[MAX], posI[MAX], posJ[MAX];
int f(int i, int j)
{
	if(n==1)
		return 0;
	if(n==2)
	{
		if(i<=1 && j<=1)
			return 0;
		if(i<=1 && j<=3)
			return 1;
		if(i<=3 && j<=1)
			return 2;
		return 3;
	}
	if(n==3)
	{
		if(i<=2 && j<=2)
			return 0;
		if(i<=2 && j<=5)
			return 1;	
		if(i<=2 && j<=8)
			return 2;			
		if(i<=5 && j<=2)
			return 3;
		if(i<=5 && j<=5)
			return 4;	
		if(i<=5 && j<=8)
			return 5;
		if(i<=8 && j<=2)
			return 6;
		if(i<=8 && j<=5)
			return 7;	
		return 8;	
	}	
}
bool bt(int pos, vi fil, vi col, vi box)
{
	if(ans[empty - 1 ] != -1) return 1;
	if(pos == empty ) return 1;
	bool flag = 0;
	for(int k=1;k<=9;k++)
	{
		int mask=(1<<k);
		int nf=mask & fil[posI[pos]], nc=mask & col[posJ[pos]], nb=mask & box[f(posI[pos], posJ[pos])];
		if(!(nf | nc | nb))//posible poner k
		{
			vi nfil (fil.begin(), fil.end());
			vi ncol (col.begin(), col.end());
			vi nbox (box.begin(), box.end());
			nfil[posI[pos]]|=mask;
			ncol[posJ[pos]]|=mask;
			nbox[f(posI[pos], posJ[pos])]|=mask;
			ans[pos]=k;
			flag|= bt(pos+1, nfil, ncol, nbox);
			if(flag) break;
		}
	}
	return flag;
}
int main()
{
	bool blank=0;
	while(cin>>n)
	{
		if(blank) cout<<endl;
		blank=1;
		vi fil (n*n, 0);
		vi col (n*n, 0);
		vi box (n*n, 0);
		empty=0;
		memset(ans, -1, sizeof ans);
		//cout<<"en"<<endl;
		for(int i=0;i<n*n;i++)
			for(int j=0;j<n*n;j++)
			{
				cin>>a[i][j];
				//cout<<i<<" - "<<j<<endl;
				if(a[i][j] != 0)
				{
					fil[i] |=(1<<a[i][j]);
					col[j] |=(1<<a[i][j]);
					box[f(i,j)]|=(1<<a[i][j]);
				}
				if(a[i][j] == 0)
				{
					posI[empty]=i;
					posJ[empty]=j;
					empty++;
				}	
			}
		//cout<<"pas"<<endl;	
		if(bt(0, fil, col, box))
		{
			int k=0;
			for(int i=0;i<n*n;i++)
			{
				for(int j=0;j<n*n;j++)
				{
					if(a[i][j]) cout<<a[i][j];
					else cout<<ans[k++];
					if(j+1<n*n) cout<<" ";
				}
				cout<<endl;
			}	
		}
		else
		{
			cout<<"NO SOLUTION"<<endl;
		}
			
	}
}
