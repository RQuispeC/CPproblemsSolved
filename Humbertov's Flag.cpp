#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<set>
#include<bitset>
using namespace std;
double PI=M_PI;
struct point
{
	int x, y;
	double angle;
	long long dis;
	point(){}
	point(int X, int Y)
	{
		x=X;
		y=Y;
		dis=x*x+y*y;
		if(x==0 && y==0)
			angle=0;
		else
		{
			double an=atan((double)y/(double)x)* 180 / PI;
			if(y==0 && x<0) angle=180;
			else if(x>0 && y>0) angle=an;
			else if(x<0 && y> 0 )  angle=180.0+an;
			else if(x<0 && y<0 )  angle=180+an;
			else if(x>0 && y<0) angle=360.0+an;
			else if(x==0 && y<0) angle= 270;
			else angle=an;
		}	
	}
	bool operator < (point  X) const
	{
		if(angle!=X.angle )
			return angle<X.angle;
		return dis<X.dis;	
	}
};
int n;
point a [105];
int main()
{	
	while(cin>>n)
	{	
		for(int k=0;k<n;k++)
		{
			int i, j;
			cin>>i>>j;
			a[k]=point(i, j);
		}
		sort(a, a+n);
		cout<<n<<endl;
		for(int i=0;i<n;i++)
			cout<<a[i].x<<" "<<a[i].y<<endl;
			
	}
}

