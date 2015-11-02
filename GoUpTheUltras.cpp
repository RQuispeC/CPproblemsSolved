#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int n;
int a[300010];
int izq[300010];
int der[300010];
vector < int > picos; 
int ST[300010];
void build(int x, int i, int j)
{
	if(i==j)
		ST[x]=a[i];
	else
	{
		int m=(i+j)/2;
		build(x*2, i ,  m);
		build(x*2+1, m+1, j);
		ST[x]=min(ST[x*2], ST[2*x+1]);		
	}		
}
int rmq(int x, int i, int j, int iq, int jq)
{
	if(iq<=i && j<=jq) return ST[x];
	if(j<iq || jq<i ) return 10000000;
	int m=(i+j)/2;
	int q1=rmq(2*x, i, m, iq, jq);
	int q2=rmq( 2*x+1, m+1, j, iq, jq);
	return min( q1, q2 ) ;
}
bool pico( int i)
{
	if(i==0 || i==n-1) return false;
	return a[i]>a[i-1] && a[i]>a[i+1]; 
}
int main()
{
	const int ultra=150000; 
	while(cin>>n)
	{
		picos.clear();
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		build(1, 0, n-1);
		for(int i=0;i<n;i++)
			if(pico(i))
				picos.push_back(i);
		for(int i=0;i<picos.size();i++)
		{
			izq[i]=-1;
			der[i]=-1;	
		}			
		izq[0]=picos[0];	
		der[picos.size()-1]=picos[picos.size()-1];
		for(int i=0;i+1<picos.size();i++)
		{
			int j=i+1;
			if(a[picos[i]]<a[picos[j]]) der[i]=picos[j];
			if(a[picos[i]]>a[picos[j]]) izq[j]=picos[i]; 
		}
		for(int i=0;i<picos.size();i++)
		{
			if(izq[i]==-1)
			{
				int j=i-1;
				izq[i]=picos[i];
				for(j;j>=0 ;j--)
				{
					if(a[picos[j]]> a[picos[i]])
					{
						izq[i]=picos[j];
						break;
					}	
				}
			}	
			if(der[i]==-1)
			{
				int j=i+1;
				der[i]=picos[i];
				for(j;j<picos.size();j++)
				{
					if(a[picos[j]]> a[picos[i]])
					{
						der[i]=picos[j];
						break;
					}
				}
			}
		}
		/*for(int i=0;i<picos.size();i++)
			cout<<picos[i]+1<<"  : " <<izq[i]+1<<"  "<<der[i]+1<<endl;*/
		vector < int  > ans;
		ans.clear();	
		for(int i=0;i<picos.size();i++)
		{
			bool flagD=false , flagI=false;
			int x=rmq(1, 0,n-1, picos[i], der[i] );
			int y=rmq(1, 0,n-1, izq[i], picos[i] );
			if(x!=a[picos[i]] && a[picos[i]]-x >= ultra)
				flagD=true;
			if(x==a[picos[i]] && a[picos[i]]>=ultra) flagD=true;	
			if(y!=a[picos[i]] && a[picos[i]]-y>= ultra)
				flagI=true;
			if(y==a[picos[i]] && a[picos[i]]>=ultra) flagI=true;	
			if(flagI && flagD)
			{
				ans.push_back(picos[i]);
			}
		}
		for(int i=0;i<ans.size();i++)
		{
			printf("%d", ans[i]+1);
			if(i+1<ans.size())
				printf(" ");
		}
		printf("\n");	
	}	
}

