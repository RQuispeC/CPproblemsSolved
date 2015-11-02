#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-9;
struct point 
{
	double x, y;
	point(){}
	point(double a, double b)
	{
		x=a, y=b;
	}
	bool operator < (point X) const
	{
		return x<X.x;
	}
};
struct line
{
	double a, b, c;
	line(){}
	line(double A, double B, double C)
	{
		a=A, b=B, c=C;
	}
};
line pointsToLine(point p1, point p2)
{
	if(fabs(p1.x - p2.x) < EPS)		
		return line(1,0,-p1.x);
	double a=-(p1.y-p2.y)/(p1.x-p2.x);
	double b=1.0;
	double c=-(a*p1.x) - p1.y;
	return line(a,b,c);
}
point lineInterPoint(point l, point r, double last)
{
	line li=pointsToLine(l,r);
	if(li.b == 0)
		return point(-li.c, last);
	return point(-((last+li.c)/li.a),last);
}
double dist(point p1, point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) +  (p1.y-p2.y)*(p1.y-p2.y));
}
point a[30005];
int n;
int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			a[i]=point(x, y);
		}
		sort(a, a+n);
		double maxAlt=0.0;
		double ans=0.0;
		for(int i=n-1;i>0;i--)
		{
			point l=a[i-1];
			point r=a[i];
			if(l.y > r.y && (l.y-maxAlt)>EPS)
			{
				point c=lineInterPoint(l, r, maxAlt);
				ans+=dist(l, c);
				maxAlt=l.y;
			}
		}
		printf("%.2lf\n", ans);
	}
}

