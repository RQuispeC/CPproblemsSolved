#include<bits/stdc++.h>
#define MAX 6000
using namespace std;
typedef vector < int  > vi;
int a[MAX], b[MAX];
int level[7]={1<<10, 1<<8, 1<<6, 1<<4, 1<<2,1, 0};
string x, y;
int f(char x)
{
	if(x=='p')
		return 2;
	if(x=='f')
		return 1;
	if(x=='p')
		return 0;		
}
int builtA(int i, int pos, int numP)
{
	a[i]=f(x[pos]);
	if(x[pos] != 'p')		
	{
		return 0;
	}	
	int next=pos +1+ numP*4;
	numP+=builtA(i*4+1, next,0);
	if(x[next]=='p')
		numP++;
	next=pos +2+ numP*4;		
	numP+=builtA(i*4+2, next,0);
	if(x[next]=='p')
		numP++;
	next=pos +3+ numP*4;
	numP+=builtA(i*4+3, next,0);
	if(x[next]=='p')
		numP++;
	next=pos +4+ numP*4;
	numP+=builtA(i*4+4, next,0);
	if(x[next]=='p')
		numP++;
	return numP;
}
int builtB(int i, int pos, int numP)
{
	b[i]=f(y[pos]);
	if(y[pos] != 'p')
	{
		return 0;
	}	
	int next=pos +1+ numP*4;
	numP+=builtB(i*4+1, next,0);
	if(y[next]=='p')
		numP++;
	next=pos +2+ numP*4;
	numP+=builtB(i*4+2, next,0);
	if(y[next]=='p')
		numP++;
	next=pos +3+ numP*4;
	numP+=builtB(i*4+3, next,0);
	if(y[next]=='p')
		numP++;
	next=pos +4+ numP*4;
	numP+=builtB(i*4+4, next,0);
	if(y[next]=='p')
		numP++;	
	return numP;
}
int sol(int i, int lev)
{
	if(a[i]==1 || b[i]==1)
		return level[lev];
	if(a[i]==0 && b[i]==0)
		return 0;
	int ans=0;
	for(int k=1;k<=4;k++)
		ans+=sol(i*4+k, lev+1);
	return ans;
}
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		cin>>x>>y;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		builtA(0,0,0);
		builtB(0,0,0);
		cout<<"There are "<<sol(0, 0)<<" black pixels."<<endl;
	}
}

