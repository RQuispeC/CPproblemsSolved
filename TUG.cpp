#include<bits/stdc++.h>
#define MAX 100010
using namespace std;
int n, x[MAX], num[105];
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		memset(num, 0, sizeof num);
		bool f=0;
		scanf("%d", &n);
		if(n>100 ) f=1;
		for(int i=0;i<n;i++)
		{
			scanf("%d", &x[i]);
			num[x[i]]++;
			if(num[x[i]]>1) f=1;
		}
		if(n>7) f=1;
		if(!f)
		{
			vector < int > v;
			v.clear();
			for(int i=1;i<(1<<n);i++)
			{
				int sum=0;
				for(int j=0;j<n;j++)
					if(i & (1<<j))
						sum+=x[j];
				v.push_back(sum);
			}
			sort(v.begin(),v.end());
			for(int i=0;i+1<v.size();i++)
				if(v[i]==v[i+1])
				{
					f=1;
					break;
				}	
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");	
					
	}
}

