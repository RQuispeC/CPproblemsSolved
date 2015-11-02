#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX 1010
using namespace std;
long long distan[MAX][MAX];
int n;
long long x[MAX];
long long y[MAX];
long long dis( int i, int j)
{
	return (y[j]-y[i])*(y[j]-y[i]) +  (x[j]-x[i])*(x[j]-x[i]); 
}
void precalculo()
{
	for(int i=0; i<n ;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(i==j)
			{
				distan[i][j]=0ll;
			}
			else
			{
				long long aux=dis(i,j);
				distan[i][j]=aux;
				distan[j][i]=aux;
			}
		}	 
	}
}
int main()
{
	vector < long long > ele;
	map < long long , long  long > sameDistance;	
	while(cin>>n)
	{
		if(n==0 ) break;
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		precalculo();
		long long ans=0;
		for(int i=0; i < n ;i++)
		{
			//mapeamos los elementos
			ele.clear();
			sameDistance.clear();
			for(int j=0;j<n;j++)
			{
				if(sameDistance[distan[i][j]]==0)// primera vez
				{
					sameDistance[ distan[i][j] ]++;
					ele.push_back(distan[i][j]);
				}
				else
					sameDistance[ distan[i][j] ]++;
			}
			for(int j=0;j<ele.size();j++)
			{
				long long vezes=sameDistance[ ele[j] ];
				ans+= ((vezes-1)*vezes)/2 ;
			}	 
		}
		cout<<ans<<endl;	
	}
}
/*int j=i+1; 
			int k=i+2;
			while(true)
			{
				if(j>=n-1 && k>=n-1) break;
				if(evaluar(i,j,k)) ans++;
				//cout<<i<<" : "<<j<<" : "<<k<<endl;
				if(k==n-1)
				{
					j++;
					k=j+1;
				}
				else k++;
							
			}*/
