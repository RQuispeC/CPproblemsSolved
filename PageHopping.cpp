#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#include<vector>
#include<cstdio>
#define INF 10000000
using namespace std;
int main()
{
	map <  int , int > mapa;
	int m[105][105];
	int x, y;
	int test=1;
	while(cin>>x>>y)
	{
		if(x<=0 && y<=0) break;
		mapa.clear();
		memset(m , -1, sizeof m);
		int num=1;
		if(mapa[x-1]==0)
		{
			mapa[x-1]=num++;
		}
		if(mapa[y-1]==0)
		{
			mapa[y-1]=num++;
		}
		m[mapa[x-1]][mapa[y-1]]=1;
		while(cin>>x>>y )
		{
			if(x<=0 && y<=0) break;
			if(mapa[x-1]==0)
			{
				mapa[x-1]=num++;
			}
			if(mapa[y-1]==0)
			{
				mapa[y-1]=num++;
			}
			m[mapa[x-1]][mapa[y-1]]=1;
		}
		for(int i=1;i<num;i++)
			for(int j=1;j<num;j++)
				if(i==j) m[i][j]=0;
				else if(m[i][j]==-1) m[i][j]=INF;
		for(int k=1;k<num;k++)
			for(int i=1;i<num;i++)
				for(int j=1;j<num;j++)
					m[i][j]=min(m[i][j], m[i][k]+ m[k][j]);
		double ans=0;
		for(int i=1;i<num;i++)
			for(int j=1;j<num;j++)
				ans+=m[i][j];
		num--;		
		num=num*(num-1);
		printf("Case %d: average length between pages = %.3f clicks\n", test++,ans/(double)num);					
	}
}

