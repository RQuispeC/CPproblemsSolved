#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, c;
	cin>>n>>c;
	int  ans=0;
	int aux;
	cin>>aux;
	ans=min(ans,aux);
	for(int i=1;i<n;i++)
	{
		int aux1, dif;
		cin>>aux1;
		dif=aux-aux1;
		ans=max(ans,dif);
		aux=aux1;
	}
	ans-=c;
	if(ans<0) ans=0;
	cout<<ans<<endl;	
}
