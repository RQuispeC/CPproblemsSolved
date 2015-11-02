/*
ID: your_id_here
PROG: beads
LANG: C++ 
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
string a;
int main() {
    ofstream fcout ("beads.out");
    ifstream fcin ("beads.in");
	fcin>>n>>a;
	int ans=0;
	bool nf=false;
	for(int k=0;k<n;k++)
	{
		char corI=a[k], corJ=(k==0?a[n-1]:a[k-1]);
		int i=k, j=(k==0? n-1:k-1);
		int iniJ=j, iniI=i,aux=i , cont=0;
		bool flag=false;
		while(corI=='w')
		{
			aux=(aux+1)%n;
			corI=a[aux];
			cont++;
			if(cont>=n) flag=true;
			if(flag) break;
		}
		if(flag)
		{
			nf=true;
		}
		if(!flag)
		{	
			aux=j;
			while(corJ=='w')
			{
				aux=(aux+n-1)%n;
				corJ=a[aux];
			}
			//cout<<j<<" "<<i<<endl;
			while(true)
			{
				int nextI=(i+1)%n;
				if(nextI==iniI) break;
				if(!(a[nextI]==corI || a[nextI]=='w')) break;
				i=nextI;
			}
			while(true)
			{
				int nextJ=(j+n-1)%n;
				if(nextJ==iniJ || nextJ==i) break;
				if(!(a[nextJ]==corJ || a[nextJ]=='w')) break;
				j=nextJ;
			}
			//cout<<k<<" : "<<endl;
			//cout<<corJ<<"  :  "<<corI<<endl;
			//cout<<j<<"  "<<i<<endl;	
			int mi, mj;
			if(i>=k) mi=i-k+1;
			else mi=n-k+i+1;
			if(j<k) mj=k-j;
			else mj=k+n-j;
			//cout<<mj<<"  **  "<<mi<<endl;
			if(mi==n && mj==n )
			{
				nf=true;
			}
			ans=max(ans, mi + mj);
		}
	}
	if(nf) fcout<<n<<endl;
	else fcout<<ans<<endl;
	return 0;
}
