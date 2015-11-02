#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<vector>
using namespace std;
int main()
{	
	int n , m;
	int a[105];
	int esp[105];
	scanf("%d %d", &n ,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	/*for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	*/for(int i=0;i<m;i++)
	{
		scanf("%d", &esp[i]);
		esp[i]--;
	}
	
	sort(esp, esp+m);
	/*for(int i=0;i<m;i++)
	{
		cout<<esp[i]<<"  ";
	}
	cout<<endl;
	*/long long aux=0ll;
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(i!=esp[k] || k==m)
		{
			//cout<<i<<"  :  "<<esp[k]<<"  *  "<<k<<endl;
			aux=aux+a[i];
		}
		if(i==esp[k] && k<n)
		{
			//cout<<"eas"<<endl;
			k++;		
		}
	}
	//cout<<" normal  :"<<aux<<endl;
	int numEsp[105];
	for(int i=0;i<m;i++)
	{
		numEsp[i]=a[esp[i]];
	}
	sort(numEsp, numEsp+m);
	/*for(int i=0;i<m;i++)
	{
		cout<<numEsp[i]<<"  ";
	}
	cout<<endl;
	*/if(aux>=numEsp[m-1])
	{
		//cout<<"as :  "<<m<<endl;
		long long ans=aux;
		for(int i=0;i<m;i++)
			ans+=ans;
		cout<<ans<<endl;	
	}
	else
	{
		//cout<<"es"<<endl;
		long long ans=aux+(long long)numEsp[m-1];
		for(int i=1;i<m;i++)
			ans+=ans;
		cout<<ans<<endl;
	}
}
