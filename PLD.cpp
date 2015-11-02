#include<bits/stdc++.h>
#define X1 31
#define X2 37
#define MAX 30005
using namespace std;
typedef long long ll;
int k;
string s, sr;
ll hs1[MAX], hsr1[MAX], hs2[MAX], hsr2[MAX];
ll pot1[MAX], pot2[MAX];
map < string , ll > mapa;
void invertir()
{
	sr="";
	for(int i=s.size()-1;i>=0 ;i--)
		sr+=s[i];
}
void precalc()
{
	for(int i=0;i<s.size();i++)
	{
		if(i==0)
		{
			pot1[i]=pot2[i]=1ll;
			hs1[i]= ll(s[i]-'a');
			hsr1[i]= ll(sr[i]-'a');
			hs2[i]= ll(s[i]-'a');
			hsr2[i]= ll(sr[i]-'a');
		}	
		if(i>=1)
		{
			pot1[i]=pot1[i-1]*X1;
			pot2[i]=pot2[i-1]*X2;
			hs1[i]=hs1[i-1]*X1 + (s[i]-'a');
			hsr1[i]=hsr1[i-1]*X1 + (sr[i]-'a');
			hs2[i]=hs2[i-1]*X2 + (s[i]-'a');
			hsr2[i]=hsr2[i-1]*X2 + (sr[i]-'a');
		}	
	}
}
ll h1(int i, int j)
{
 	if(i==0)
 		return hs1[j];
 	return hs1[i]-hs1[j-1]*pot1[i-j+1];
 		
}
ll h2(int i, int j)
{
 	if(i==0)
 		return hs2[j];
 	return hs2[i]-hs2[j-1]*pot2[i-j+1];
 		
}
ll hr1(int i, int j)
{
	if(i==0)
 		return hsr1[j];
 	return hsr1[i]-hsr1[j-1]*pot1[i-j+1];
}
ll hr2(int i, int j)
{
	if(i==0)
 		return hsr2[j];
 	return hsr2[i]-hsr2[j-1]*pot2[i-j+1];
}
int main()
{
	cin>>k>>s;
	if(k>s.size())
		cout<<0<<endl;
	else	
	{
		invertir();
		precalc();
		int ans=0, l =s.size();
		for(int i=k-1;i<s.size();i++)
		{
			int j=i-k+1;
			//cout<<h1(i, j) <<" : "<< hr1(l-j-1, l-i-1)<<endl;
			//cout<<h2(i, j) <<" : "<< hr2(l-j-1, l-i-1)<<endl;
			if(h1(i, j) == hr1(l-j-1, l-i-1) && h2(i, j) == hr2(l-j-1, l-i-1))
			{
				ans++;
				
			}
				
		}
		cout<<ans<<endl;
	}
}

