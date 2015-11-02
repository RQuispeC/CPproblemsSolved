#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector < int > a;
bool orden(int x, int y)
{
	int mx,my;
	if( x < 0 ) mx=-1*((-1*x)%m);
	else mx=x%m;
	if( y < 0 ) my=-1*((-1*y)%m);
	else my=y%m;
	if(mx != my)
		return mx<my;
	else
	{
		int X,Y;
		if( x < 0 ) X=(-1*x)%2;
		else X=x%2;
		if( y < 0 ) Y=(-1*y)%2;
		else Y=y%2;
		if(X==0 && Y==0 ) return y>x;
		if(X==1 && Y==1 ) return y<x;
		if(X!=Y) return X>Y;
	}
}
int main()
{ 
	while(cin>>n>>m)
	{
		cout<<n<<" "<<m<<endl;
		if(n==0 && m==0) break;
		a.clear();
		for(int i=0;i<n;i++)
		{
			int aux;
			cin>>aux;
			a.push_back(aux);
		}
		sort(a.begin(),a.end(), orden);
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<endl;
		}
	}
}
