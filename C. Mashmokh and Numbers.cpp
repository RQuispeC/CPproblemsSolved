#include<iostream>
#include<cstdio>
#define INF 1000000000
using namespace std;
int main()
{	
	int n, k;
	scanf("%d %d", &n , &k);
	if(n/2>k || (n==1 && k>0))
		cout<<-1<<endl;
	else
	{
		if(n==1 && k==0) cout<<1<<endl;
		else
		{
			int falt=n/2;
			falt--;
			//cout<<falt<<endl;
			cout<<k-falt<<" "<<2*(k-falt)<<" ";
			int co=2*(k-falt)+1;
			for(int i=2;i<n;i++)
			{
				printf("%d", co++);
				if(i+1<n) printf(" ");
				//if(co+1>INF) co=k-falt+1;
				//else co++;
			}
			printf("\n");
		}	
	}	
}
