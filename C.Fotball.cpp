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
int n, k;
int main()
{	
	cin>>n>>k;
	int totPar=((n-1)*n)/2;
	if(k*n>totPar)
		cout<<-1<<endl;
	else
	{
		cout<<k*n<<endl;
		int limit=totPar/n;
		for(int ki=1;ki<=k;ki++)
		{
			for(int i=1;i<=n;i++)
			{
				int ne=i+ki;
				if(ne>n) ne%=n;
				if(ne)
				printf("%d %d\n", i,ne );
			}
		}
	}
}
