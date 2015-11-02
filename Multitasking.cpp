#include<bits/stdc++.h>
using namespace std;
typedef pair < int, int > pii;
typedef vector < pii > vii;
int n, m;
vii a, b;
int main()
{
	int t[(int)1e6 +5 ];
	while(scanf("%d %d",&n , &m))
	{
		if(n==0 && m==0) break;
		memset(t, 0, sizeof t);
		bool f=1;
		for(int i=0;i<n;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			if(f)
			for(int j=u;j<v && f;j++)
			{
				t[j]++;	
				if(t[j]>=2) f=0;
			}	
		}
		for(int i=0;i<m;i++)
		{
			int u, v, ti;
			scanf("%d %d %d", &u, &v, &ti);
			if(f)
			{
				int fact=0;
				while(fact*ti + u <=(int)1e6)
				{
					int ini=fact*ti;
					for(int j=ini+ u;j<(int)1e6 && j<ini+v && f;j++ )
					{
						t[j]++;	
						if(t[j]>=2) f=0;
					}
					fact++;
					if(!f) break;
				}
			}	
		}
		if(f)
			cout<<"NO CONFLICT"<<endl;
		else
			cout<<"CONFLICT"<<endl;	
	}
}

