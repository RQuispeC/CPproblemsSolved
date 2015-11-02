#include<bits/stdc++.h>
#define MAX 105
using namespace std;
int main()
{
	int tested, n ,  m, a[MAX];
	scanf("%d", &tested);
	while(tested--)
	{
		scanf("%d %d", &n, &m);
		int maxi=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			maxi=max(maxi, a[i]);
		}
		bool f=1;
		for(int i=0;i<n;i++)
		{
			m-=(maxi - a[i]);
			if(m<0)
				f=0;
		}
		if(m % n != 0)
			f=0;
		cout<<(f?"Yes":"No")<<endl;
	}
}

