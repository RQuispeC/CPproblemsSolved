#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tested, g , r, b, m;
	scanf("%d", &tested);
	while(tested--)
	{
		scanf("%d %d %d %d", &r, &g, &b, &m);
		int a[3];
		a[0]=a[1]=a[2]=0;
		for(int i=0;i<r;i++)
		{
			int aux;
			scanf("%d", &aux);
			a[0]=max(a[0], aux);
		}	
		for(int i=0;i<g;i++)
		{
			int aux;
			scanf("%d", &aux);
			a[1]=max(a[1], aux);
		}
		for(int i=0;i<b;i++)
		{
			int aux;
			scanf("%d", &aux);
			a[2]=max(a[2], aux);
		}
		for(int i=0;i<m;i++)
		{
			sort(a,a+3);
			a[2]/=2;
		}
		sort(a,a+3);
		cout<<a[2]<<endl;
	}
}

