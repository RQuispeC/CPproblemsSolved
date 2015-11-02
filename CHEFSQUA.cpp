#include<bits/stdc++.h>
#define MAX 1000005
using namespace std;
typedef long long ll;
typedef pair < int, int > ii;
int n;
vector < int > x,y;
map < ii , int > mapa;
bool exist (ii punto)
{
	return mapa.count(punto);
}
int need(int i, int j)
{
	if(x[i]==x[j] && y[i]==y[j] ) return 3;
	if(x[i] > x [j]) // punto i (x) < punto j (x)
		swap(i,j);
	//vectores direccion transpuestos
	ii d1=ii(-(y[j]-y[i]),x[j]-x[i]);
	ii d2=ii(-(y[i]-y[j]),x[i]-x[j]);
	//puntos que forman cuadrados
	ii p1=ii(d1.first  + x[i], d1.second + y[i] );
	ii p2=ii(d1.first  + x[j], d1.second + y[j] );
	ii p3=ii(d2.first  + x[i], d2.second + y[i] );
	ii p4=ii(d2.first  + x[j], d2.second + y[j] );
	//cuadrado sobre la recta
	int posib1=0;
	if(exist(p1))
	{
		posib1++;
	}	
	if(exist(p2))
	{
		posib1++;
	}	
	//cuadrado bajo la recta
	int posib2=0;
	if(exist(p3))
	{
		posib2++;
	}	
	if(exist(p4))
	{
		posib2++;
	}
	return 2 - max(posib1 , posib2);
}
int main()
{
	mapa.clear();
	scanf("%d", &n);
	if(n<=2)
	{
		printf("%d\n", 4-n);
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		int X,Y;
		scanf("%d %d", &X, &Y);
		mapa[ii(X,Y)]=1;
		x.push_back(X);
		y.push_back(Y);
	}
	int ans=4;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ans=min(ans, need(i,j));
			if(ans==0)
				break;
		}
	}
	printf("%d\n", ans);
}

