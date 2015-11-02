#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MAX 105
using namespace std;
struct island
{
	int x, y, radio;
	island(){}
	island(int a, int b, int r)
	{
		x=a;
		y=b;
		radio=r;
	}
};
int n, m;
island is[MAX];
double dp[MAX][MAX];
const double INF=1000000000.00;
double dis(island a, island b)
{
	double disRa=sqrt(double((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y)));
	return disRa;
}
bool overlap(island a, island b)
{
	double di=dis(a, b);
	if(di> double(a.radio+b.radio))
		return false;
	return true;	
}
int main()
{
	int tested;
	scanf("%d", &tested);
	bool blank=false;
	while(tested--)
	{
		if(blank) cout<<endl;
		blank=true;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			is[i]=island(x,y,r);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=INF;
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				if(i==j || overlap(is[i], is[j]))
				{
					dp[i][j]=0.0;
					dp[j][i]=0.0;
				}
				else
				{
					dp[i][j]=dis(is[i], is[j])- double(is[i].radio+is[j].radio);
					dp[j][i]=dp[i][j];
				}
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					dp[i][j]=min(dp[i][j], dp[i][k]+ dp[k][j]);
		scanf("%d", &m);
		for(int i=0;i<m;i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%.4f\n", dp[a][b]);
		}
					
	}
}
