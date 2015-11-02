#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-9;
const double INF=DBL_MAX;
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
struct vec
{
	double x , y;
	vec(double _x, double _y): x(_x),y(_y){}
};
vec toVec( point a, point b)
{
	return vec(b.x - a.x , b.y - a.y);
}
vec scale(vec v, double s)
{
	return vec(v.x*s, v.y*s);
}
point translate(point p, vec v)
{
	return  point(p.x + v.x, p.y + v.y);
}
double dot(vec a, vec b)
{
	return a.x*b.x + a.y*b.y;
}
double norm_sq(vec v)
{
	return v.x*v.x + v.y*v.y;
}
double dist(point p1, point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) +  (p1.y-p2.y)*(p1.y-p2.y));
}
int n;
point a[500005];
double distToLine(point p, point a, point b, point &c)
{
	vec ap=toVec(a,p), ab =toVec(a,b);
	double u=dot(ap,ab) / norm_sq(ab);
	c=translate(a, scale(ab,u ));
	return dist(c, p);
}
double distToLineSegment(point p, point a, point b, point &c)
{
	vec ap=toVec(a,p), ab =toVec(a,b);
	double u=dot(ap,ab) / norm_sq(ab);
	if(u < 0.0)
	{
		c=point(a.x,a.y);
		return dist(p,a);
	}
	if(u > 1.0)
	{
		c=point(b.x,b.y);
		return dist(p,b);
	}
	return distToLine(p, a, b, c);
}
int main()
{
	point m;
	while(cin>>m.x>>m.y)
	{
		scanf("%d", &n);
		for(int i=0;i<=n;i++)
		{
			int x, y;
			scanf("%d", &x), scanf("%d", &y);
			a[i]=point(x,y);
		}
		point ans;
		double minDist=INF;
		for(int i=0;i<n;i++)
		{
			point c;
			double d=distToLineSegment(m, a[i], a[i+1], c);
			if(d < minDist)
			{
				minDist=d;
				ans=c;
			}
		}
		printf("%.4lf\n%.4lf\n", ans.x, ans.y);
	}
}
