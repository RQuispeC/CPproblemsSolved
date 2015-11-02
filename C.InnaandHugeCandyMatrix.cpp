#include<iostream>
using namespace std;
struct point
{
	int i,j;
	point(int a , int b)
	{
		i=a;
		j=b;
	}
	point()
	{
		i=-1;
		j=-1;
	}
};
point horRot(point a, int n, int m)
{
	return point(a.i , m+1-a.j );
}
point verRot(point a, int n, int m)
{
	return point(n+1-a.i, a.j);
}
point invert ( point a)
{
	return point(a.j, a.i);
}
int main()
{
	int n, m, x, y , z, p;
	cin>>n>>m>>x>>y>>z>>p;
	x=x%4;
	y=y%2;
	z=z%4;		
	for(int k=0;k<p;k++)
	{
		int i, j;
		cin>>i>>j;
		point ans=point(i,j);
		if(x==1)
		{
			ans=horRot(invert(ans), m , n);
		}
		else if(x==2)
		{
			ans=verRot(horRot (ans, n, m) , n , m);		
		}
		else if(x==3)
		{
			ans=verRot(invert ( ans ), m ,n);
		}
		if(y==1)
		{
			ans=horRot(ans, n , m);
		}
		if(z==1)
		{
			ans=verRot(invert ( ans ), m ,n);
		}
		else if(z==2)
		{
			ans=verRot(horRot (ans, n, m) , n , m);				
		}
		else if(z==3)
		{
			ans=horRot(invert(ans), m , n);
		}
		cout<<ans.i<<" "<<ans.j<<endl;
	}
}

