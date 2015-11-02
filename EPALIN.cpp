#include<bits/stdc++.h>
#define X1 31 
#define X2 37
#define MAX 100005
using namespace std;
typedef unsigned long long ll;
int lim;
char s[MAX], sr[MAX];
ll hs1[MAX], hsr1[MAX], hs2[MAX], hsr2[MAX];
ll pot1[MAX], pot2[MAX];
void precalc()
{
	for(int i=0;i<lim;i++)
	{
		if(i==0)
		{
			pot1[i]=pot2[i]=1ll;
			hs1[i]= ll(s[i]-' '+1);
			hsr1[i]= ll(sr[i]-' '+1);
			hs2[i]= ll(s[i]-' '+1);
			hsr2[i]= ll(sr[i]-' '+1);
		}	
		if(i>=1)
		{
			pot1[i]=pot1[i-1]*X1;
			pot2[i]=pot2[i-1]*X2;
			hs1[i]=hs1[i-1]*X1 + (s[i]-' '+1);
			hsr1[i]=hsr1[i-1]*X1 + (sr[i]-' '+1);
			hs2[i]=hs2[i-1]*X2 + (s[i]-' '+1);
			hsr2[i]=hsr2[i-1]*X2 + (sr[i]-' '+1);
		}	
	}
}
ll h1(int i, int j) 
{
 	if(i==0)
 		return hs1[j];
 	return hs1[j]-hs1[i-1]*pot1[j-i+1];
 		
}
ll h2(int i, int j)
{
 	if(i==0)
 		return hs2[j];
 	return hs2[j]-hs2[i-1]*pot2[j-i+1];
 		
}
ll hr1(int i, int j)
{
	if(i==0)
 		return hsr1[j];
 	return hsr1[j]-hsr1[i-1]*pot1[j-i+1];
}
ll hr2(int i, int j) 
{
	if(i==0)
 		return hsr2[j];
 	return hsr2[j]-hsr2[i-1]*pot2[j-i+1];
}
bool isPal(int i, int j)
{
	return h1(i,j)==hr1(lim-j-1,lim-i-1) && h2(i,j)==hr2(lim-j-1,lim-i-1);
}
int main()
{
	while(scanf("%s", s)==1)
	{
		lim=strlen(s);
		strcpy(sr, s);
		reverse(sr, sr+ lim);
		precalc();
		vector < int > pos;
		pos.clear();
		for(int i=0;i+1<lim;i++)
		{
			if(s[i]==s[lim-1])
			{
				pos.push_back(i);
			}	
		}
		int posBreak=lim-1;
		for(int i=0;i<pos.size();i++)
		{
			if(isPal(pos[i]+1, lim-2))
			{
				posBreak=pos[i];
				break;
			}
		}
		printf("%s", s);
		for(int i=posBreak-1;i>=0;i--)
			printf("%c", s[i]);
		printf("\n");	
	}
}
