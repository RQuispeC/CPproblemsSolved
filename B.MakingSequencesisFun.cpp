#include<iostream>
#include<cmath>
using namespace std;
long long w,m,k;
long long f(long long limit, int digit,  long long ans)
{
	long long aux=(long long) pow (10.0,digit);
			cout<<"*****   "<<digit<<"  :  "<<limit<<"  ,  "<<ans<<endl;
	cout<<(aux-ans)*k*digit<<endl;	
	if(limit>=(aux-ans)*k*digit && (aux-ans)*k*digit>0) //evitar desbordes
	{	
		limit-=(aux-ans)*k*digit;
		ans+=(aux-ans);
		return f(limit, digit+1,ans);
	}
	else
	{
		cout<<" _   "<<limit/(digit*k)<<endl;
		return ans+limit/(digit*k);		
	}
}
int main()
{
	cin>>w>>m>>k;
	//cout<<w<<"  :  "<<m<<"   :   "<<k<<endl;
	int aux=m;
	int digitos=0;
	while(m>0)
	{
		digitos++;
		m=m/10;
	}
	//cout<<"dig :  "<<digitos<<endl;
	long long ans=f(w,digitos,aux);
	ans-=aux;
	cout<<ans<<endl;
}

