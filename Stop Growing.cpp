#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
ll a0,a1,b0,b1,c0,c1,d1,d0,e1,e0, m;
int main()
{
	int test;
	scanf("%d", &test);
	for(int t=1;t<=test;t++)
	{
		cin>>a0>>b0>>c0>>d0>>e0>>m;
		int cont=0;
		bool f=1;
		ll suma=a0 + b0 +c0 +d0+ e0, suma2,difA, difD;
		difA=m- suma;
		while(suma<m)
		{
			//cout<<suma<<"* "<<endl;	
			a1=a0 + b0;
			b1=b0 + c0;
			c1=c0 + d0;
			d1=d0 + e0;
			e1=e0 + a0;
			cont++;
			if(a0== a1 && b0== b1 && c0== c1 && d0== d1 && e0== e1)
			{
				f=0;
				break;				
			}
			a0=a1;
			b0=b1;
			c0=c1;
			d0=d1;
			e0=e1;
			suma2=a0 + b0 +c0 +d0+ e0;
			difD=m - suma2;
			if(suma2 >= m ) break;
			if(difD >= difA)
			{
				f=0;
				break;
			}
			else
			{
				suma=suma2;	
				difA=difD;
			}
		}
		if(f)
			cout<<"Case #"<<t<<": "<<cont<<endl;	
		else
			cout<<"Case #"<<t<<": "<<-1<<endl;
	}
}
